#include "DicomToJPGClass.h"
DicomToJPGClass::DicomToJPGClass(QObject *parent)
	: QObject(parent)
{
}

DicomToJPGClass::~DicomToJPGClass()
{
}

// 读---调节亮度---jpg---写
bool  DicomToJPGClass::convertDcm2JpgSlot(/*float minData, float maxData*/)
{
	//定义输入的类型
	typedef signed short InputPixelType;
	const unsigned int inputDimension = 2;
	typedef itk::Image<InputPixelType, inputDimension> InputImageType;

	//设置输出类型
	typedef unsigned char OutputPixelType;
	const unsigned int OutputDimension = 2;
	typedef itk::Image<OutputPixelType, OutputDimension> OutputImageType;

	//设置输入的DCM图像
	typedef itk::ImageFileReader < InputImageType > ReaderType;
	ReaderType::Pointer reader = ReaderType::New();
	//设置DCM类型
	typedef itk::GDCMImageIO Imageiotype;
	Imageiotype::Pointer gdcmImageIo = Imageiotype::New();
	reader->SetImageIO(gdcmImageIo);

	typedef itk::IntensityWindowingImageFilter<InputImageType, OutputImageType> windowFilter;
	windowFilter::Pointer wFilter = windowFilter::New();
		wFilter->SetOutputMaximum(255);
		wFilter->SetOutputMinimum(0);

	//亮度调节后的
// 	typedef itk::RescaleIntensityImageFilter<InputImageType, OutputImageType> RescaleFilterType;
// 	RescaleFilterType::Pointer rescaler = RescaleFilterType::New();
// 	rescaler->SetOutputMinimum(0);
// 	rescaler->SetOutputMaximum(255);

	typedef unsigned char InputPixelType1;
	typedef itk::Image<InputPixelType1, inputDimension> InputImageType1;
	typedef itk::CastImageFilter<InputImageType1, OutputImageType> ImageCastType1;
	ImageCastType1::Pointer imageCast1 = ImageCastType1::New();

	typedef itk::ImageFileWriter<OutputImageType> WriterType;
	WriterType::Pointer writer1 = WriterType::New();

	typedef itk::JPEGImageIO bmpType;
	bmpType::Pointer jpgIO = bmpType::New();
	writer1->SetImageIO(jpgIO);

	for (auto iter = m_convertMaps.begin(); iter != m_convertMaps.end(); iter++)
	{
		bool val = iter.value();
		// 如果已经被转化，不再转化
		if (val == true)
			continue;
		QString path = iter.key();
		int pos = path.lastIndexOf(".dcm");
		QString jpgName = path.replace(pos, 4, QString(".jpg"));
		reader->SetFileName(iter.key().toStdString().c_str());
		try
		{
			reader->Update();
		}
		catch (itk::ExceptionObject &e)
		{
			std::cerr << "Error Dcm Reader in function convertDcm2Jpg" << std::endl;
			std::cerr << e << std::endl;
			emit workFinished();
			return false;
		}
		wFilter->SetWindowMinimum(0);
		wFilter->SetWindowMaximum(1000);
		wFilter->SetInput(reader->GetOutput());
		//rescaler->SetInput(reader->GetOutput());
		imageCast1->SetInput(wFilter->GetOutput()/*rescaler->GetOutput()*/);
		try
		{
			imageCast1->Update();
		}
		catch (itk::ExceptionObject &e)
		{
			std::cerr << "Exception in  castImageFilter! " << std::endl;
			std::cerr << e << std::endl;
			emit workFinished();
			return false;
		}

		writer1->SetFileName(jpgName.toStdString().c_str());
		writer1->SetInput(imageCast1->GetOutput());

		try
		{
			writer1->Update();
		}
		catch (itk::ExceptionObject &e)
		{
			std::cerr << "Error in Write DCm 2 JPG!!" << std::endl;
			std::cerr << e << std::endl;
			emit workFinished();
			return false;
		}
		iter.value() = true;
	}

	emit workFinished();
	return true;
}

QMap<QString, bool> & DicomToJPGClass::getConvertMaps()
{
	return m_convertMaps;
}
