#pragma once

#include <QtWidgets/QWidget>
#include <QThread>
#include "ui_DicomBrowser.h"
#include "DicomToJPGClass.h"
#include "qcustomplot.h"
#include "ThreeDimsReconstruct.h"
class DicomBrowser : public QWidget
{
	Q_OBJECT

public:
	DicomBrowser(QWidget *parent = Q_NULLPTR);
	~DicomBrowser();
	// ����DCM�ļ�ͼ��
	bool renderDICOM2Widget(/*const char * path*/int num);
	// �����Ҳ�table��Ϣ
	void updateTableWidgets();
	// �źŲ�����
	void initConnections();
	// ����Ƿ�Ϊdcm�ļ�
	bool  dicomCheck(const char* path);
	// ��ȡ������֮���ҽѧ��Ϣ������������ȣ�
	void readTagInformations(itk::GDCMImageIO::Pointer &);
	// ������״ͼ
	void drawBarGraph();
	// ��ʼ������б��ͼ
	void initCustomPlot();
	// ͨ����ק�Ҳ������߸ı䴰λ�ʹ���
	void updateDcmDisplayByDragLine();

	public slots:
	// �����ļ�
	void loadBtnClickedSlot();
	// ��һ��
	void preBtnClicked();
	// ��һ��
	void nextBtnClicked();
	// ������λ
	void windowCenterChangedSlot(const QString&);
	// ��������
	void windowWidthChangedSlot(const QString&);
	// �л�����ά����ƽ���
	void switchTo3DBtnClickedSlot();
private:
	Ui::DicomBrowserClass ui;
	QVector<int> m_DcmCounts;//DICOM�ļ�����
	QMap<int, QString> m_DcmMaps;// <�ڼ���ͼƬ���ļ�����>
	QMap<QString, QString>m_PatientInfoMap; // ��¼Patient��Ϣ
	QMap<QString, QString>m_StudyInfoMap; // ��¼Study��Ϣ
	QMap<QString, QString>m_SeriesInfoMap; // ��¼Series��Ϣ
	QMap<QString, QString>m_ImageInfoMap; // ��¼Image��Ϣ
	unsigned int m_Current;	// ��¼��ǰ��ʾͼƬ�����кţ�
	DicomToJPGClass *m_dicom2JpgPointer;// dicom ת��jpg
	float m_windowCenter;// ��λ
	float m_windowWidth; // ����
	QThread * m_thread;
	QCustomPlot * m_barGraphPlot;
	QMap<int,int> m_CTValueRatioMap; // �洢���׶�CTֵ������
	int m_CtMax;  // CTֵ���ֵ
	int m_CtMin;  // CTֵ��Сֵ
	ThreeDimsReconstruct * m_p3DimsReconstruct; // ��ά�����ģ��
};
