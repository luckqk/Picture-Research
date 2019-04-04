#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PictureResearch.h"
#include "BmpProcess.h"



class PictureResearch : public QMainWindow
{
	Q_OBJECT

public:
	BMPINFO curBmp;			//当前的bmp图片

	PictureResearch(QWidget *parent = Q_NULLPTR);
	~PictureResearch();

private:
	QPixmap curPixmap;		//当前的图片
	float	pixRatio;		//当前图片缩放比例


	/*bmp 相关*/
	void displayImage(const QString &aFileName);
	void getBMPfileInfo(const QString &aFileName);

private slots:
	void on_actOpen_triggered();

private:
	Ui::PictureResearchClass *ui;
};
