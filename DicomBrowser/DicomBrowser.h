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
	// 绘制DCM文件图像
	bool renderDICOM2Widget(/*const char * path*/int num);
	// 更新右侧table信息
	void updateTableWidgets();
	// 信号槽连接
	void initConnections();
	// 检查是否为dcm文件
	bool  dicomCheck(const char* path);
	// 获取处像素之外的医学信息（姓名、年龄等）
	void readTagInformations(itk::GDCMImageIO::Pointer &);
	// 绘制柱状图
	void drawBarGraph();
	// 初始化像素斜率图
	void initCustomPlot();
	// 通过拖拽右侧像素线改变窗位和窗宽
	void updateDcmDisplayByDragLine();

	public slots:
	// 加载文件
	void loadBtnClickedSlot();
	// 上一张
	void preBtnClicked();
	// 下一张
	void nextBtnClicked();
	// 调整窗位
	void windowCenterChangedSlot(const QString&);
	// 调整窗宽
	void windowWidthChangedSlot(const QString&);
	// 切换到三维体绘制界面
	void switchTo3DBtnClickedSlot();
private:
	Ui::DicomBrowserClass ui;
	QVector<int> m_DcmCounts;//DICOM文件个数
	QMap<int, QString> m_DcmMaps;// <第几张图片，文件名称>
	QMap<QString, QString>m_PatientInfoMap; // 记录Patient信息
	QMap<QString, QString>m_StudyInfoMap; // 记录Study信息
	QMap<QString, QString>m_SeriesInfoMap; // 记录Series信息
	QMap<QString, QString>m_ImageInfoMap; // 记录Image信息
	unsigned int m_Current;	// 记录当前显示图片的序列号；
	DicomToJPGClass *m_dicom2JpgPointer;// dicom 转换jpg
	float m_windowCenter;// 窗位
	float m_windowWidth; // 窗宽
	QThread * m_thread;
	QCustomPlot * m_barGraphPlot;
	QMap<int,int> m_CTValueRatioMap; // 存储各阶段CT值的数量
	int m_CtMax;  // CT值最大值
	int m_CtMin;  // CT值最小值
	ThreeDimsReconstruct * m_p3DimsReconstruct; // 三维体绘制模块
};
