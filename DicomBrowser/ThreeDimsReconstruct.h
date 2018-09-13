#pragma once

#include <QWidget>
#include "ui_ThreeDimsReconstruct.h"

class ThreeDimsReconstruct : public QWidget
{
	Q_OBJECT

public:
	ThreeDimsReconstruct(QWidget *parent = Q_NULLPTR);
	~ThreeDimsReconstruct();
	Ui::ThreeDimsReconstruct* getUiPointer()
	{
		return &ui;
	}
private:
	Ui::ThreeDimsReconstruct ui;
};
