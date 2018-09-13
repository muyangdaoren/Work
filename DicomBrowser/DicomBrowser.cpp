#include "DicomBrowser.h"
#include <vtkAutoInit.h> 
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
#include <vtkSmartPointer.h>
#include <vtkObject.h>
#include <vtkDICOMImageReader.h>
#include <vtkImageViewer2.h>
#include <QVTKWidget.h>
#include <itkImageToVTKImageFilter.h>
#include <vtkImageFlip.h>
#include <vtkJPEGReader.h>//
#include <vtkImageViewer2.h>//
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
//#include <vtkImageMapToWindowLevelColors.h>
#include <QFileDialog>
#include <QDebug>
#include <QLineEdit>
DicomBrowser::DicomBrowser(QWidget *parent)
	: QWidget(parent)
{
	vtkObject::GlobalWarningDisplayOff();
	ui.setupUi(this);
	m_windowWidth = 500;
	m_windowCenter = 1000;
	m_CtMax = 1024;
	m_CtMin = -1024;
	m_thread = new QThread(this);
	m_dicom2JpgPointer = new DicomToJPGClass;
	m_dicom2JpgPointer->moveToThread(m_thread);
	initConnections();
	initCustomPlot();
	m_p3DimsReconstruct = new ThreeDimsReconstruct();
	m_p3DimsReconstruct->hide();
}

DicomBrowser::~DicomBrowser()
{
	if (m_thread)
	{
		if (m_thread->isRunning())
		{
			m_thread->quit();
			m_thread->wait();
		}
		delete m_thread;
		m_thread = nullptr;
	}
	if (m_dicom2JpgPointer)
	{
		delete m_dicom2JpgPointer;
		m_dicom2JpgPointer = nullptr;
	}
	if (m_p3DimsReconstruct)
	{
		delete m_p3DimsReconstruct;
		m_p3DimsReconstruct = nullptr;
	}
}

bool DicomBrowser::renderDICOM2Widget(int num)
{
	m_CTValueRatioMap.clear();
	// 获取当前dcm路径
	std::string path = "";
	if (num < m_DcmCounts.size())
	{
		path = m_DcmMaps[num].toStdString();
	}
	if (path == "")
	{
		qDebug() << "read the DcmContent Failed! the  path is Empty!" << endl;
		return false;
	}
	// 数据类型
	typedef signed short InputPixelType;
	const unsigned int InputDimension = 2;
	typedef itk::Image<InputPixelType, InputDimension> ImageType;
	typedef itk::ImageFileReader<ImageType> ReaderType;

	ReaderType::Pointer reader = ReaderType::New();
	//读取文件路径
	reader->SetFileName(path);
	typedef itk::GDCMImageIO           ImageIOType;
	ImageIOType::Pointer gdcmImageIO = ImageIOType::New();
	reader->SetImageIO(gdcmImageIO);
	try
	{
		//开始读取数据
		reader->Update();
		reader->GetMetaDataDictionary();
		gdcmImageIO->GetMetaDataDictionary();
		readTagInformations(gdcmImageIO);
	}
	catch (itk::ExceptionObject &ex)
	{
		std::cout << ex << std::endl;
		return false;
	}

	// **************************************************
	////定义输入的类型
	//typedef signed short inPixelType;
	//const unsigned int inputDimension = 2;
	//typedef itk::Image<inPixelType, 2> InImageType;

	////设置输出类型
	//typedef unsigned char OutPixelType;
	//const unsigned int OutputDimension = 2;
	//typedef itk::Image<OutPixelType, 2> OutImageType;

	//typedef itk::IntensityWindowingImageFilter<InImageType, InImageType> windowFilter;
	//windowFilter::Pointer wFilter = windowFilter::New();

	//float windowMin = m_windowCenter - m_windowWidth / 2 + 0.5;
	//float windowMax = m_windowCenter + m_windowWidth / 2 + 0.5;
	//wFilter->SetWindowMinimum(windowMin);
	//wFilter->SetWindowMaximum(windowMax);
	//wFilter->SetInput(reader->GetOutput());
	// **************************************************

	// 存储dcm对应的像素数据
	ImageType::Pointer image = reader->GetOutput();
	typedef itk::ImageRegionIterator<ImageType>ItType;
	ItType it(image, image->GetRequestedRegion());
	it.GoToBegin();
	while (!it.IsAtEnd())
	{
		ImageType::PixelType value = it.Get();
		if (value > m_CtMax || value <= m_CtMin)
		{
			++it;
			continue;
		}
		auto itFind = m_CTValueRatioMap.find(value);
		if (itFind == m_CTValueRatioMap.end())
		{
			m_CTValueRatioMap[value] = 0;
		}
		else
			m_CTValueRatioMap[value] += 1;
		++it;
	}

	// 图像数据从ITK转向VTK
	typedef itk::ImageToVTKImageFilter< ImageType> itkTovtkFilterType;
	itkTovtkFilterType::Pointer itkTovtkImageFilter = itkTovtkFilterType::New();
	itkTovtkImageFilter->SetInput(reader->GetOutput());
	itkTovtkImageFilter->Update();

	// vtk、Itk显示图像时y轴相反，所以翻转一次
	vtkImageFlip * flip = vtkImageFlip::New();
	flip->SetInputData(itkTovtkImageFilter->GetOutput());
	flip->SetFilteredAxes(1);
	flip->Update();

	vtkImageViewer2 * viewer = vtkImageViewer2::New();
	viewer->SetInputData(flip->GetOutput());
	viewer->SetRenderWindow(ui.qvtkWidget->GetRenderWindow());
	//int dims[3];
	//flip->GetOutput()->GetDimensions(dims);
	//for (int i = 0; i < dims[0]; i++)
	//{
	//	for (int j = 0; j < dims[1]; j++)
	//	{
	//		for (int k = 0; k < dims[2]; k++)
	//		{
	//			unsigned char *pData = (unsigned char *)flip->GetOutput()->GetScalarPointer(i, j, k);
	//			std::cout << " pData = " << QString::fromLocal8Bit((const char*)pData).toUInt() << std::endl;
	//		}
	//	}
	//}
	// 设置窗位窗宽
	viewer->SetColorWindow(m_windowWidth);
	viewer->SetColorLevel(m_windowCenter);
	viewer->Render();

	viewer->Delete();
	flip->Delete();
	drawBarGraph();
	return true;
}

void DicomBrowser::updateTableWidgets()
{
	ui.patientTable->clear();
	ui.studyTable->clear();
	ui.seriesTable->clear();
	ui.imageTable->clear();

	ui.patientTable->setColumnCount(m_PatientInfoMap.size());
	ui.patientTable->setRowCount(1);
	ui.seriesTable->setColumnCount(m_SeriesInfoMap.size());
	ui.seriesTable->setRowCount(1);
	ui.studyTable->setColumnCount(m_StudyInfoMap.size());
	ui.studyTable->setRowCount(1);
	ui.imageTable->setColumnCount(m_ImageInfoMap.size());
	ui.imageTable->setRowCount(1);

	ui.patientTable->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:lightblue;color:black;padding-left:4px;border:1px solid#6c6c6c;}");
	ui.seriesTable->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:lightblue;color:black;padding-left:4px;border:1px solid#6c6c6c;}");
	ui.studyTable->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:lightblue;color:black;padding-left:4px;border:1px solid#6c6c6c;}");
	ui.imageTable->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:lightblue;color:black;padding-left:4px;border:1px solid#6c6c6c;}");

	ui.patientTable->horizontalHeader()->setFixedHeight(25);
	ui.seriesTable->horizontalHeader()->setFixedHeight(25);
	ui.studyTable->horizontalHeader()->setFixedHeight(25);
	ui.imageTable->horizontalHeader()->setFixedHeight(25);

	ui.patientTable->horizontalHeader()->setStretchLastSection(true);
	ui.seriesTable->horizontalHeader()->setStretchLastSection(true);
	ui.studyTable->horizontalHeader()->setStretchLastSection(true);
	ui.imageTable->horizontalHeader()->setStretchLastSection(true);
	int col = 0;
	for (auto iter = m_PatientInfoMap.begin(); iter != m_PatientInfoMap.end(); iter++)
	{
		ui.patientTable->setHorizontalHeaderItem(col, new QTableWidgetItem(iter.key()));
		ui.patientTable->setItem(0, col++, new QTableWidgetItem(iter.value()));
	}
	col = 0;
	for (auto iter = m_SeriesInfoMap.begin(); iter != m_SeriesInfoMap.end(); iter++)
	{
		ui.seriesTable->setHorizontalHeaderItem(col, new QTableWidgetItem(iter.key()));
		ui.seriesTable->setItem(0, col++, new QTableWidgetItem(iter.value()));
	}
	col = 0;
	for (auto iter = m_StudyInfoMap.begin(); iter != m_StudyInfoMap.end(); iter++)
	{
		ui.studyTable->setHorizontalHeaderItem(col, new QTableWidgetItem(iter.key()));
		ui.studyTable->setItem(0, col++, new QTableWidgetItem(iter.value()));
	}
	col = 0;
	for (auto iter = m_ImageInfoMap.begin(); iter != m_ImageInfoMap.end(); iter++)
	{
		ui.imageTable->setHorizontalHeaderItem(col, new QTableWidgetItem(iter.key()));
		ui.imageTable->setItem(0, col++, new QTableWidgetItem(iter.value()));
	}
}

void DicomBrowser::readTagInformations(itk::GDCMImageIO::Pointer &gdcmIO)
{
	std::string key = "";
	std::string val = "";

	// Patient Tag
	key = "0010|0010";
	gdcmIO->GetValueFromTag(key, val);
	m_PatientInfoMap.insert(QString("name"), QString::fromStdString(val));
	key = "0010|0020";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_PatientInfoMap.insert(QString("patientID"), QString::fromStdString(val)); 
	key = "0010|0030";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_PatientInfoMap.insert(QString("birthDay"), QString::fromStdString(val));
	key = "0010|0040";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_PatientInfoMap.insert(QString("sex"), QString::fromStdString(val));

	// Study Tag
	key = "0008|0050";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_StudyInfoMap.insert(QString("accessionNumber"), QString::fromStdString(val));
	key = "0020|0010";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_StudyInfoMap.insert(QString("studyID"), QString::fromStdString(val));
	key = "0020|000D";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_StudyInfoMap.insert(QString("studyInstanceUID"), QString::fromStdString(val));
	key = "0008|0020";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_StudyInfoMap.insert(QString("studyDate"), QString::fromStdString(val));
	key = "0008|0030";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_StudyInfoMap.insert(QString("studyTime"), QString::fromStdString(val));
	key = "0008|0015";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_StudyInfoMap.insert(QString("bodyPart"), QString::fromStdString(val));
	key = "0008|1030";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_StudyInfoMap.insert(QString("studyDescription"), QString::fromStdString(val));
	key = "0010|1010";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_StudyInfoMap.insert(QString("studyPatientAge"), QString::fromStdString(val));

	// Series Tag
	key = "0020|0011";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_SeriesInfoMap.insert(QString("SeriesNumber"), QString::fromStdString(val));
	key = "0020|000E";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_SeriesInfoMap.insert(QString("SeriesInstanceUID"), QString::fromStdString(val));
	key = "0008|0060";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_SeriesInfoMap.insert(QString("modality"), QString::fromStdString(val));
	key = "0008|103E";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_SeriesInfoMap.insert(QString("seriesDescription"), QString::fromStdString(val));
	key = "0020|0032";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_SeriesInfoMap.insert(QString("ImagePosition"), QString::fromStdString(val));
	key = "0020|0037";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_SeriesInfoMap.insert(QString("ImageOrientation"), QString::fromStdString(val));
	key = "0018|0023";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_SeriesInfoMap.insert(QString("MRAquisition"), QString::fromStdString(val));
	key = "0018|0050";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_SeriesInfoMap.insert(QString("sliceThickness"), QString::fromStdString(val));

	// Image Tag
	key = "0008|0018";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_ImageInfoMap.insert(QString("sopInstanceUID"), QString::fromStdString(val));
	key = "0008|0023";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_ImageInfoMap.insert(QString("contentDate"), QString::fromStdString(val));
	key = "0020|0013";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_ImageInfoMap.insert(QString("imageNumber"), QString::fromStdString(val));
	key = "0028|1050";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_ImageInfoMap.insert(QString("windowCenter"), QString::fromStdString(val)); 
	key = "0028|1051";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_ImageInfoMap.insert(QString("windowWidth"), QString::fromStdString(val)); 
	key = "0028|0102";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_ImageInfoMap.insert(QString("hightBit"), QString::fromStdString(val));
	key = "0028|0010";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_ImageInfoMap.insert(QString("rows"), QString::fromStdString(val));
	key = "0028|0011";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_ImageInfoMap.insert(QString("columns"), QString::fromStdString(val));
	key = "0028|1053";
	val.clear();
	gdcmIO->GetValueFromTag(key, val);
	m_ImageInfoMap.insert(QString("rescaleSlope"), QString::fromStdString(val)); std::cout << "rescaleSlope:" << val << std::endl;

}

void DicomBrowser::drawBarGraph()
{
	
	ui.qcustomplot->graph(0)->data()->clear();
	ui.qcustomplot->graph(1)->data()->clear();
	ui.qcustomplot->graph(2)->data()->clear();
	for (auto it = m_CTValueRatioMap.begin(); it != m_CTValueRatioMap.end(); it++)
	{
		ui.qcustomplot->graph(0)->addData(it.key(), it.value());
	}

	ui.qcustomplot->graph(1)->addData(0, 0);
	float windowMin = m_windowCenter - (m_windowWidth / 2);
	float windowMax = m_windowCenter + (m_windowWidth / 2);
	ui.qcustomplot->graph(1)->addData(0, 0);
	ui.qcustomplot->graph(1)->addData(windowMin, 0);
	ui.qcustomplot->graph(1)->addData(windowMax, 200);
	ui.qcustomplot->graph(1)->addData(windowMax + 500, 200);
	QPen pen;
	pen.setWidth(2);
	pen.setColor(Qt::red);
	ui.qcustomplot->graph(1)->setPen(pen);

	ui.qcustomplot->graph(2)->addData(m_windowCenter, 100);
	pen.setColor(Qt::green);
	ui.qcustomplot->graph(2)->setPen(pen);
	ui.qcustomplot->graph(2)->setScatterStyle(QCPScatterStyle::ssCross);

	ui.qcustomplot->replot();
	m_CTValueRatioMap.clear();
}

void DicomBrowser::initCustomPlot()
{
	// 灰度曲线
	ui.qcustomplot->setInteractions(QCP::iSelectAxes | QCP::iSelectPlottables |QCP::iRangeDrag);
	ui.qcustomplot->setViewport(QRect(0, 0, 300, 300));
	ui.qcustomplot->xAxis->setLabel("CT Value");
	ui.qcustomplot->yAxis->setLabel("pixel");
	ui.qcustomplot->addGraph();
	ui.qcustomplot->graph(0)->setName(QString("斜率曲线"));
	ui.qcustomplot->xAxis->setRange(0, m_CtMax);
	ui.qcustomplot->yAxis->setRange(0, 1500);
	QPen pen;
	pen.setWidth(0.5);
	ui.qcustomplot->graph(0)->setPen(pen);
	pen.setWidth(1);
	ui.qcustomplot->graph(0)->setPen(pen);
	ui.qcustomplot->graph(0)->setBrush(QBrush(Qt::lightGray));
	ui.qcustomplot->xAxis->setUpperEnding(QCPLineEnding::esLineArrow);
	ui.qcustomplot->yAxis->setUpperEnding(QCPLineEnding::esLineArrow);
	ui.qcustomplot->graph(0)->setSelectable(QCP::stNone);

	// 窗位-窗宽线
	ui.qcustomplot->addGraph();
	ui.qcustomplot->graph(1)->setName(QString("窗位-窗宽"));
	

	// 窗位点
	ui.qcustomplot->addGraph();
	ui.qcustomplot->graph(2)->setName(QString("窗位"));
	ui.qcustomplot->graph(2)->setSelectable(QCP::stNone);
}

void DicomBrowser::updateDcmDisplayByDragLine()
{

}

void DicomBrowser::initConnections()
{
	connect(ui.loadBtn, SIGNAL(clicked()), this, SLOT(loadBtnClickedSlot()));
	connect(ui.preBtn, SIGNAL(clicked()), this, SLOT(preBtnClicked()));
	connect(ui.nextBtn, SIGNAL(clicked()), this, SLOT(nextBtnClicked()));
	connect(m_thread, SIGNAL(started()), m_dicom2JpgPointer, SLOT(convertDcm2JpgSlot()), Qt::QueuedConnection);
	connect(m_dicom2JpgPointer, SIGNAL(workFinished()), m_thread, SLOT(quit()));
	connect(ui.windowCenterEdit, SIGNAL(textChanged(const QString &)), this, SLOT(windowCenterChangedSlot(const QString &)));
	connect(ui.windowWidthEdit, SIGNAL(textChanged(const QString &)), this, SLOT(windowWidthChangedSlot(const QString &)));
	connect(ui.switchTo3DBtn, SIGNAL(clicked()), this, SLOT(switchTo3DBtnClickedSlot()));
}

void DicomBrowser::loadBtnClickedSlot()
{
	QStringList paths = QFileDialog::getOpenFileNames(this, QString("Open Files"), QString("./"), QString("Files(*.dcm)"));
	int count = 0;
	if (paths.size() != 0)
	{
		if (!m_DcmCounts.isEmpty())
			m_DcmCounts.clear();
		if (!m_DcmMaps.isEmpty())
			m_DcmMaps.clear();
		bool isFind = false;
		for (auto it = paths.begin(); it != paths.end(); it++)
		{
			bool isDcm = dicomCheck(it->toStdString().c_str());
			if (isDcm)
			{
				m_DcmCounts.push_back(count);
				m_DcmMaps.insert(count++, *it);
				auto itFind = m_dicom2JpgPointer->getConvertMaps().find(*it);
				if (itFind != m_dicom2JpgPointer->getConvertMaps().end())
				{
					continue;
				}
				else
				{
					isFind = true;
					m_dicom2JpgPointer->getConvertMaps().insert(*it, false);
				}

			}
		}
		if (isFind)
			m_thread->start();
	}

	// 默认打开第一张
	m_Current = 0;
	renderDICOM2Widget(m_Current);
	updateTableWidgets();
}

void DicomBrowser::preBtnClicked()
{
	if (m_Current == 0)
		m_Current = m_DcmCounts.size() - 1;
	else
		m_Current--;
	renderDICOM2Widget(m_Current);
	updateTableWidgets();
}

void DicomBrowser::nextBtnClicked()
{
	if (m_Current == m_DcmCounts.size() - 1)
		m_Current = 0;
	else
		m_Current++;
	renderDICOM2Widget(m_Current);
	updateTableWidgets();
}

void DicomBrowser::windowCenterChangedSlot(const QString& text)
{
	//if (text.isEmpty())
	//	m_windowCenter = 500;
	//else
		m_windowCenter = ui.windowCenterEdit->text().toFloat();
	renderDICOM2Widget(m_Current);
}

void DicomBrowser::windowWidthChangedSlot(const QString& text)
{
	//if (text.isEmpty())
	//	m_windowWidth = 1000;
	//else
		m_windowWidth = ui.windowWidthEdit->text().toFloat();
	renderDICOM2Widget(m_Current);
}

void DicomBrowser::switchTo3DBtnClickedSlot()
{
	this->hide();
	m_p3DimsReconstruct->show();
}

bool  DicomBrowser::dicomCheck(const char* path)
{
	FILE* f = NULL;
	char flag[4];
	if (f = fopen(path, "r"))
	{
		fseek(f, 128, 0);
		char* temp = fgets(flag, 5, f);
		fclose(f);
		int val = QString::compare(QString(temp).left(4), QString("DICM"), Qt::CaseSensitive);
		if (val == 0)
			return true;
		else
			return false;
	}
	return false;
}
//void DicomBrowser::Test()
//{
//	// 加载jpg到vtk显示
//	vtkSmartPointer<vtkJPEGReader> jpegReader = vtkSmartPointer<vtkJPEGReader>::New();
//	jpegReader->SetFileName("E:\\Projects\\Test\\test\\1.jpg");
//	//// Visualize
//	vtkSmartPointer<vtkImageViewer2> imageViewer2 = vtkSmartPointer<vtkImageViewer2>::New();
//	imageViewer2->SetInputConnection(jpegReader->GetOutputPort());
//	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
//	imageViewer2->SetupInteractor(renderWindowInteractor);
//	//*
//	//imageViewer2->SetupInteractor(/*renderWindowInteractor*/ui.qvtkWidget->GetRenderWindow()->GetInteractor());
//	//ui.qvtkWidget->SetRenderWindow(imageViewer2->GetRenderWindow());
//	//*
//	imageViewer2->SetColorLevel(150);
//	imageViewer2->SetColorWindow(300);
//	imageViewer2->Render();
//	imageViewer2->GetRenderer()->ResetCamera();
//	imageViewer2->Render();
//	imageViewer2->GetRenderWindow()->SetWindowName("read and show jpg test");
//
//	renderWindowInteractor->Start();
//}


