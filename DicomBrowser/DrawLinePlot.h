#pragma once

#include <QWidget>
#include <qcustomplot.h>
class DrawLinePlot : public QWidget,public QCustomPlot
{
	Q_OBJECT

public:
	DrawLinePlot(QWidget *parent = nullptr);
	~DrawLinePlot();
	void initCustomPlot();
	void drawLines();
	void setPoints(QMap<int,int>&);
	void setPoints(QVector<int>&, QVector<int>&);
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);

private:

};
