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
// ת��dcm�ļ���jpg
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
	QMap<QString, bool> m_convertMaps; // keyֵΪdcm���ƣ�value�Ƿ�ת��Ϊjpg<dcmName,true/false>
	float m_windowMin;// ������Сֵ
	float m_windowMax;// ���ֵ
};
