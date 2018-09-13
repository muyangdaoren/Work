#pragma once

#include <QObject>
#include <itkImageFileWriter.h>
#include <itkJPEGImageIO.h>
#include <itkGDCMImageIO.h>
#include "itkRescaleIntensityImageFilter.h"
#include <itkIntensityWindowingImageFilter.h>
#include "itkCastImageFilter.h"
#include "itkImageFileReader.h"
#include <stdlib.h>
#include <QMap>
#include <QVector>
// 转换dcm文件到jpg
class DicomToJPGClass : public QObject
{
	Q_OBJECT

public:
	DicomToJPGClass(QObject *parent = nullptr);
	~DicomToJPGClass();
	QMap<QString, bool> & getConvertMaps();
	public slots:
	bool convertDcm2JpgSlot(/*float minData,float maxData*/);
signals:
	void workFinished();
private:
	QMap<QString, bool> m_convertMaps; // key值为dcm名称，value是否转换为jpg<dcmName,true/false>
	float m_windowMin;// 窗口最小值
	float m_windowMax;// 最大值
};
