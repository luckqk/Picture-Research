#include "PictureResearch.h"
#include <qdir.h>
#include <qfiledialog.h>
#include <qtextcodec.h>

PictureResearch::PictureResearch(QWidget *parent)
	: QMainWindow(parent),
	ui(new Ui::PictureResearchClass)
{
	ui->setupUi(this);
}

PictureResearch::~PictureResearch()
{
	delete ui;
}


/*打开bmp文件->显示图片*/
void PictureResearch::displayImage(const QString &aFileName)
{
	curPixmap.load(aFileName);
	/*适应高度显示图片*/
	int H = ui->scrollArea->height();
	int W = ui->scrollArea->width();
	int realH = curPixmap.height();
	int realW = curPixmap.width();
	pixRatio = float(realH-30) / H;
	int Chg_H = realH-30;
	int Chg_W = pixRatio * realW;
	QPixmap pix = curPixmap.scaled(Chg_W,Chg_H);
	ui->LabPicture->setPixmap(pix);
}

/*打开bmp文件->获取bmp相关信息*/
void PictureResearch::getBMPfileInfo(const QString &aFileName)
{
	curBmp.bmpInfo_Init(aFileName);
	QString strTmp;

	/*tabBitmapFileHeader 数据显示*/
	strTmp = strTmp.sprintf("%d", curBmp.bmpHeader.bfType);
	ui->lineEtBfType->setText(strTmp);
	strTmp = strTmp.sprintf("%d", curBmp.bmpHeader.bfSize);
	ui->lineEtBfSize->setText(strTmp);
	strTmp = strTmp.sprintf("%d", curBmp.bmpHeader.bfReserved1);
	ui->lineEtBfReserved1->setText(strTmp);
	strTmp = strTmp.sprintf("%d", curBmp.bmpHeader.bfReseverd2);
	ui->lineEtBfReserved2->setText(strTmp);
	strTmp = strTmp.sprintf("%d", curBmp.bmpHeader.bfOffBits);
	ui->lineEtBfOffBits->setText(strTmp);

	/*tabBitmapInfoHeader 数据显示*/
	strTmp = strTmp.sprintf("%d", curBmp.bmpInfoHeader.biSize);
	ui->lineEtBiSize->setText(strTmp);
	strTmp = strTmp.sprintf("%d", curBmp.bmpInfoHeader.biWidth);
	ui->lineEtBiWidth->setText(strTmp);
	strTmp = strTmp.sprintf("%d", curBmp.bmpInfoHeader.biHeight);
	ui->lineEtBiHeight->setText(strTmp);
	strTmp = strTmp.sprintf("%d", curBmp.bmpInfoHeader.biPlanes);
	ui->lineEtBiPlane->setText(strTmp);
	strTmp = strTmp.sprintf("%d", curBmp.bmpInfoHeader.biBitCount);
	ui->lineEtBiBitCnt->setText(strTmp);
	strTmp = strTmp.sprintf("%d", curBmp.bmpInfoHeader.biCompression);
	ui->lineEtBiCompression->setText(strTmp);
	strTmp = strTmp.sprintf("%d", curBmp.bmpInfoHeader.biSizeImage);
	ui->lineEtBiSizImg->setText(strTmp);
	strTmp = strTmp.sprintf("%d", curBmp.bmpInfoHeader.biXPelsPerMeter);
	ui->lineEtBiXPelsPerM->setText(strTmp);
	strTmp = strTmp.sprintf("%d", curBmp.bmpInfoHeader.biYPelsPerMeter);
	ui->lineEtBiYPelsPerM->setText(strTmp);
	strTmp = strTmp.sprintf("%d", curBmp.bmpInfoHeader.biClrUsed);
	ui->lineEtBiClrUsed->setText(strTmp);
	strTmp = strTmp.sprintf("%d", curBmp.bmpInfoHeader.biClrImportant);
	ui->lineEtBiClrImportant->setText(strTmp);
}


/*打开文件槽函数*/
void PictureResearch::on_actOpen_triggered()
{
	/*获得文件路径 aFileName*/
	QString curPath = QDir::currentPath();
	QString dlgTitle = QString::fromLocal8Bit("打开一个文件");
	QString filter = QString::fromLocal8Bit("图像文件(*.jpg *.bmp);;程序文件(*.h *.cpp);;\
											文本文件(*.txt);;所有文件(*.*)");
	QString aFileFull = QFileDialog::getOpenFileName(this, dlgTitle, curPath, filter);
	if (aFileFull.isEmpty())
		return;
	/*获得文件相关信息 aFileInfo*/
	QFileInfo aFileInfo(aFileFull);
	QString  aFile_name, aFile_path, aFile_suffix;
	aFile_name = aFileInfo.fileName();
	aFile_path = aFileInfo.absolutePath();
	aFile_suffix = aFileInfo.suffix();

	/*判断文件格式打开*/
	if (aFile_suffix.contains("bmp", Qt::CaseInsensitive)) {
		displayImage(aFileFull);
		getBMPfileInfo(aFileFull);
	}

}