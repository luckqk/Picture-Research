/*****************************
bmp文件相关处理	CPP
2019/1/5
******************************/
#include "BmpProcess.h"
#include "DataProcess.h"

#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>

#include <QDir>

using namespace std;


/*BMPINFO类构造函数,路径构造*/
BMPINFO::BMPINFO(const QString &bmpName)
{
	if (bmpName != NULL) {
		QFile bmpFile(bmpName);
		if (!(bmpFile.open(QIODevice::ReadOnly))) {
			return;
		}
		QDataStream bmpStream(&bmpFile);
		bmpStream.setByteOrder(QDataStream::LittleEndian);

		/*读出位图头文件*/
		bmpStream.readRawData((char*)&bmpHeader.bfType, sizeof(bmpHeader.bfType));
		bmpStream.readRawData((char*)&bmpHeader.bfSize, sizeof(bmpHeader.bfSize));
		bmpStream.readRawData((char*)&bmpHeader.bfReserved1, sizeof(bmpHeader.bfReserved1));
		bmpStream.readRawData((char*)&bmpHeader.bfReseverd2, sizeof(bmpHeader.bfReseverd2));
		bmpStream.readRawData((char*)&bmpHeader.bfOffBits, sizeof(bmpHeader.bfOffBits));

		if (0x4d42 != bmpHeader.bfType) {
			cerr << "非BMP图片" << endl;
			return;
		}
		/*读出位图信息数据结构*/
		bmpStream.readRawData((char*)&bmpInfoHeader, sizeof(bmpInfoHeader));
		colorNum = bmpInfoHeader.biClrUsed;
		/*对位数进行判断，24位为真彩色，不保存调色板数据*/
		if (bmpInfoHeader.biBitCount != 24) {
			/*对colorNum进行处理*/
			if (colorNum == 0) {
				colorNum = pow(2, bmpInfoHeader.biBitCount);
			}
			RGBQUAD	*colorTable_tmp = new RGBQUAD[colorNum];
			int loop;
			/*读出调色板信息*/
			for (loop = 0;loop != colorNum;loop++) {
				bmpStream.readRawData((char*)&colorTable_tmp[loop].rgbBlue, 1);
				bmpStream.readRawData((char*)&colorTable_tmp[loop].rgbGreen, 1);
				bmpStream.readRawData((char*)&colorTable_tmp[loop].rgbRed, 1);
				bmpStream.readRawData((char*)&colorTable_tmp[loop].rgbReserved, 1);
				colorTable_tmp[loop].greyLevel = (11 * colorTable_tmp[loop].rgbBlue + \
					59 * colorTable_tmp[loop].rgbGreen + \
					11 * colorTable_tmp[loop].rgbRed) / 100;
				colorTableAll.push_back(colorTable_tmp[loop]);
			}
			delete[] colorTable_tmp;
			/*读出像素信息(每一字节代表颜色索引号，对应该号调色板中的颜色*/
			IMAGEDATA  pixel_tmp;
			int pixel_loop;
			bmpData.reserve(bmpInfoHeader.biSizeImage);
			for (pixel_loop = 0;pixel_loop != bmpInfoHeader.biSizeImage;pixel_loop++) {
				bmpStream.readRawData((char*)&pixel_tmp, 1);
				bmpData.push_back(pixel_tmp);
			}

		}
		else {
			/*bmp24位图像素点信息处理，像素从左往右，从下往上读取*/
			int PixelNum = bmpInfoHeader.biHeight * bmpInfoHeader.biWidth;
			PixelData24 *pixelData24_tmp = new PixelData24[PixelNum];
			int loop;
			for (loop = 0;loop != PixelNum;loop++) {
				bmpStream.readRawData((char*)&pixelData24_tmp[loop].rgb24Blue, 1);
				bmpStream.readRawData((char*)&pixelData24_tmp[loop].rgb24Green, 1);
				bmpStream.readRawData((char*)&pixelData24_tmp[loop].rgb24Red, 1);
				pixelData24_tmp[loop].greyLevel24 = (11 * pixelData24_tmp[loop].rgb24Blue + \
					59 * pixelData24_tmp[loop].rgb24Green + \
					11 * pixelData24_tmp[loop].rgb24Red) / 100;
				bmp24PixelData.push_back(pixelData24_tmp[loop]);
			}
			delete[] pixelData24_tmp;
		}
		bmpFile.close();
	}
	else {
		cerr << "BMP名字为空" << endl;
		/*对类进行初始化*/
		memset(&bmpHeader, 0, sizeof(bmpHeader));
		memset(&bmpInfoHeader, 0, sizeof(bmpInfoHeader));
		colorNum = -1;
	}
}

/*BMPINFO类初始化函数
  参数：bmp路径*/
void BMPINFO::bmpInfo_Init(const QString &bmpName)
{
	if (bmpName != NULL) {
		QFile bmpFile(bmpName);
		if (!(bmpFile.open(QIODevice::ReadOnly))){
			return ;
		}
		QDataStream bmpStream(&bmpFile);
		bmpStream.setByteOrder(QDataStream::LittleEndian);

		/*读出位图头文件*/
		bmpStream.readRawData((char*)&bmpHeader.bfType, sizeof(bmpHeader.bfType));
		bmpStream.readRawData((char*)&bmpHeader.bfSize, sizeof(bmpHeader.bfSize));
		bmpStream.readRawData((char*)&bmpHeader.bfReserved1, sizeof(bmpHeader.bfReserved1));
		bmpStream.readRawData((char*)&bmpHeader.bfReseverd2, sizeof(bmpHeader.bfReseverd2));
		bmpStream.readRawData((char*)&bmpHeader.bfOffBits, sizeof(bmpHeader.bfOffBits));
		
		if (0x4d42 != bmpHeader.bfType) {
			cerr << "非BMP图片" << endl;
			return;
		}
		/*读出位图信息数据结构*/
		bmpStream.readRawData((char*)&bmpInfoHeader, sizeof(bmpInfoHeader));
		colorNum = bmpInfoHeader.biClrUsed;
		/*对位数进行判断，24位为真彩色，不保存调色板数据*/
		if (bmpInfoHeader.biBitCount != 24) {
			/*对colorNum进行处理*/
			if (colorNum == 0) {
				colorNum = pow(2, bmpInfoHeader.biBitCount);
			}
			RGBQUAD	*colorTable_tmp = new RGBQUAD[colorNum];
			int loop;
			/*读出调色板信息*/
			for (loop = 0;loop != colorNum;loop++) {
				bmpStream.readRawData((char*)&colorTable_tmp[loop].rgbBlue, 1);
				bmpStream.readRawData((char*)&colorTable_tmp[loop].rgbGreen, 1);
				bmpStream.readRawData((char*)&colorTable_tmp[loop].rgbRed, 1);
				bmpStream.readRawData((char*)&colorTable_tmp[loop].rgbReserved, 1);
				colorTable_tmp[loop].greyLevel = (11 * colorTable_tmp[loop].rgbBlue + \
												  59 * colorTable_tmp[loop].rgbGreen + \
												  11 * colorTable_tmp[loop].rgbRed) / 100;
				colorTableAll.push_back(colorTable_tmp[loop]);
			}
			delete[] colorTable_tmp;
			/*读出像素信息(每一字节代表颜色索引号，对应该号调色板中的颜色*/
			IMAGEDATA  pixel_tmp;
			int pixel_loop;
			bmpData.reserve(bmpInfoHeader.biSizeImage);
			for (pixel_loop = 0;pixel_loop != bmpInfoHeader.biSizeImage;pixel_loop++) {
				bmpStream.readRawData((char*)&pixel_tmp, 1);
				bmpData.push_back(pixel_tmp);
			}
			
		}
		else {
			/*bmp24位图像素点信息处理，像素从左往右，从下往上读取*/
			int PixelNum = bmpInfoHeader.biHeight * bmpInfoHeader.biWidth;
			PixelData24 *pixelData24_tmp = new PixelData24[PixelNum];
			int loop;
			for (loop = 0;loop != PixelNum;loop++) {
				bmpStream.readRawData((char*)&pixelData24_tmp[loop].rgb24Blue, 1);
				bmpStream.readRawData((char*)&pixelData24_tmp[loop].rgb24Green, 1);
				bmpStream.readRawData((char*)&pixelData24_tmp[loop].rgb24Red, 1);
				pixelData24_tmp[loop].greyLevel24 = (11 * pixelData24_tmp[loop].rgb24Blue + \
													59 * pixelData24_tmp[loop].rgb24Green + \
													11 * pixelData24_tmp[loop].rgb24Red)/100;
				bmp24PixelData.push_back(pixelData24_tmp[loop]);
			}
			delete[] pixelData24_tmp;
		}
		bmpFile.close();
	}
	else {
		cerr << "BMP名字为空" << endl;
		/*对类进行初始化*/
		memset(&bmpHeader, 0, sizeof(bmpHeader));
		memset(&bmpInfoHeader, 0, sizeof(bmpInfoHeader));
		colorNum = -1;
	}
}


/*输出部分像素点的信息*/
int BMPINFO::iOutputPartPixelData()
{
	vector<int> colorBlueArray_tmp, colorGreenArray_tmp, colorRedArray_tmp;
	int xAxisNum, yAxisNum;
	int pixelNum;
	cout << "请输入需要查找的像素点个数" << endl;
	cin >> pixelNum;
	if (&bmpInfoHeader == NULL|| pixelNum < 0) {
		return EXIT_FAILURE;
	}
	else if(bmpInfoHeader.biBitCount != 24) {
		int					loop = 0;
		int					rgbBlue_tmp, rgbGreen_tmp, rgbRed_tmp;
		IMAGEDATA			indexNum;
		vector<int>			indexNumArray_tmp;
		vector<IMAGEDATA>::const_iterator   bmpData_it = bmpData.cbegin();
		vector<RGBQUAD>::const_iterator		colorTableAll_it = colorTableAll.cbegin();

		cout << "像素点信息:" << endl;
		cout << "(横坐标,纵坐标):(蓝，绿，红, 灰度)" << endl;
		for (loop = 0; loop < pixelNum; loop++)
		{
			/*处理横纵坐标*/
			xAxisNum = bmpInfoHeader.biHeight - ((loop + 1) / bmpInfoHeader.biWidth);
			yAxisNum = (loop + 1) % bmpInfoHeader.biWidth;
			/*每次寻找时初始化*/
			rgbBlue_tmp = 0;
			rgbGreen_tmp = 0;
			rgbRed_tmp = 0;
			colorTableAll_it = colorTableAll.cbegin();
			/*得到索引值*/
			indexNum = *bmpData_it;
			/*对Blue,Green,Red的Byte的处理*/
			iGetBooleanArray((colorTableAll_it+indexNum)->rgbBlue, colorBlueArray_tmp);
			iGetColorDataDec(colorBlueArray_tmp, rgbBlue_tmp);
			iGetBooleanArray((colorTableAll_it + indexNum)->rgbGreen, colorGreenArray_tmp);
			iGetColorDataDec(colorGreenArray_tmp, rgbGreen_tmp);
			iGetBooleanArray((colorTableAll_it + indexNum)->rgbRed, colorRedArray_tmp);
			iGetColorDataDec(colorRedArray_tmp, rgbRed_tmp);
			/*输出坐标，对应三色的值，0~255，灰度*/
			cout << "(" << xAxisNum << "," << yAxisNum << ")" << " "\
				<< "(" << rgbBlue_tmp << "," << rgbGreen_tmp << ","\
				<< rgbRed_tmp << "," << (colorTableAll_it + indexNum)->greyLevel << ")" << endl;
			/*将处理完的Vector清空*/
			colorBlueArray_tmp.clear();
			colorGreenArray_tmp.clear();
			colorRedArray_tmp.clear();
			
			bmpData_it++;
		}
		return EXIT_SUCCESS;
	}
	else {
		int loop = 0;
		int rgb24Blue_tmp, rgb24Green_tmp, rgb24Red_tmp;
		vector <PixelData24>::iterator it = bmp24PixelData.begin();

		cout << "像素点信息:" << endl;
		cout << "(横坐标,纵坐标):(蓝，绿，红, 灰度)" << endl;
		for (loop = 0;loop != pixelNum;loop++) {
			/*处理横纵坐标*/
			xAxisNum = bmpInfoHeader.biHeight - ((loop + 1) / bmpInfoHeader.biWidth);
			yAxisNum = (loop + 1) % bmpInfoHeader.biWidth;

			/*处理输出的RGB值*/
			/*每次计算前清空*/
			rgb24Blue_tmp = 0;
			rgb24Green_tmp = 0;
			rgb24Red_tmp = 0;
			/*对Blue,Green,Red的Byte的处理*/
			iGetBooleanArray(it->rgb24Blue, colorBlueArray_tmp);
			iGetColorDataDec(colorBlueArray_tmp, rgb24Blue_tmp);
			iGetBooleanArray(it->rgb24Green, colorGreenArray_tmp);
			iGetColorDataDec(colorGreenArray_tmp, rgb24Green_tmp);
			iGetBooleanArray(it->rgb24Red, colorRedArray_tmp);
			iGetColorDataDec(colorRedArray_tmp, rgb24Red_tmp);
			/*输出坐标，对应三色的值，0~255，灰度*/
			cout << "("<<xAxisNum<<","<<yAxisNum<<")"<<" "\
				 <<	"(" << rgb24Blue_tmp << "," << rgb24Green_tmp << ","\
				 << rgb24Red_tmp << "," << it->greyLevel24 << ")" << endl;
			/*将处理完的Vector清空*/
			colorBlueArray_tmp.clear();
			colorGreenArray_tmp.clear();
			colorRedArray_tmp.clear();
			it += 1;
		}
		return EXIT_SUCCESS;
	}
}
