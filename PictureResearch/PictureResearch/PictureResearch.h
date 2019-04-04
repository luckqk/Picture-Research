#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PictureResearch.h"
#include "BmpProcess.h"



class PictureResearch : public QMainWindow
{
	Q_OBJECT

public:
	BMPINFO curBmp;			//��ǰ��bmpͼƬ

	PictureResearch(QWidget *parent = Q_NULLPTR);
	~PictureResearch();

private:
	QPixmap curPixmap;		//��ǰ��ͼƬ
	float	pixRatio;		//��ǰͼƬ���ű���


	/*bmp ���*/
	void displayImage(const QString &aFileName);
	void getBMPfileInfo(const QString &aFileName);

private slots:
	void on_actOpen_triggered();

private:
	Ui::PictureResearchClass *ui;
};
