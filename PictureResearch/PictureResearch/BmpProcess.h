/******************************
bmp图片相关处理
2019/1/5
*******************************/
#ifndef _BMP_PROCESS_
#define _BMP_PROCESS_

#include <QtWidgets/QMainWindow>
#include "ui_PictureResearch.h"
#include <qstring.h>


#include <vector>


typedef unsigned char		BYTE;
typedef unsigned short int  UINT;
typedef short int			WORD;
typedef int					DWORD;
typedef long				LONG;


/*位图头文件数据结构*/
typedef struct tagBITMAPFILE_HEADER
{
	UINT	bfType;			/*文件的类型*/
	DWORD	bfSize;			/*文件的大小*/
	UINT	bfReserved1;	/*保留，设置为0*/
	UINT	bfReseverd2;	/*保留，设置为0*/
	DWORD	bfOffBits;		/*到图像数据的偏移量*/
}BITMAPFILE_HEADER;

/*位图信息数据结构*/
typedef struct tagBITMAPINFO_HEADER
{
	DWORD	biSize;			/*BITMAPINFO_HEADER结构所需的字节数*/
	LONG	biWidth;		/*图像的宽度，单位：像素，会用无意义数据补足到4的倍数*/
	LONG	biHeight;		/*图像的高度，单位：像素，会用无意义数据补足到4的倍数*/
	WORD	biPlanes;		/*位面数，值为1*/
	WORD	biBitCount;		/*颜色位数*/
	DWORD	biCompression;  /*图片压缩类型：不压缩。4/8位RLE*/
	DWORD	biSizeImage;	/*图像的实际大小，单位：字节*/
	LONG	biXPelsPerMeter;/*水平分辨率，单位：像素/米*/
	LONG	biYPelsPerMeter;/*垂直分辨率，单位：像素/米*/
	DWORD	biClrUsed;		/*位图的颜色索引数，为0表示为2^颜色位数*/
	DWORD	biClrImportant;	/*对图像显示有重要影响的颜色索引数，为0表示都重要*/
}BITMAPINFO_HEADER;

/*调色板,每种颜色含的RGB分量,颜色索引数决定*/
typedef struct tagRGBQUAD
{
	BYTE	rgbBlue;		/*蓝色强度*/
	BYTE	rgbGreen;		/*绿色强度*/
	BYTE    rgbRed;			/*红色强度*/
	BYTE	rgbReserved;	/*保留，设置为0*/
	DWORD	greyLevel;		/*灰度*/
}RGBQUAD;

/*24色像素点信息*/
typedef struct tagPixelData24
{
	BYTE	rgb24Blue;		/*24位蓝色强度*/
	BYTE	rgb24Green;		/*24位绿色强度*/
	BYTE	rgb24Red;		/*24位红色强度*/
	DWORD	greyLevel24;	/*24位灰度*/
}PixelData24;

/*位图数据*/
typedef struct tagBITMAPINFO
{
	BITMAPINFO_HEADER	bmiHeader;		/*位图信息头*/
	RGBQUAD				bmiColors[16];	/*颜色表*/
}BITMAPINFO;

/*像素信息*/
typedef unsigned char IMAGEDATA;

/*BMP类*/
class BMPINFO
{
public:
	BMPINFO() = default;
	BMPINFO(const QString &bmpName);										/*BMPINFO类构造函数,路径构造*/
	void bmpInfo_Init(const QString &bmpName);								/*BMPINFO类初始化函数*/
	~BMPINFO() {};															/*析构函数*/
	int iOutputPartPixelData();												/*输出pixelNum个像素点的信息*/

	BITMAPFILE_HEADER			bmpHeader;		/*文件头*/
	BITMAPINFO_HEADER			bmpInfoHeader;	/*文件头信息*/
	DWORD						colorNum;		/*颜色索引数*/
	std::vector<RGBQUAD>		colorTableAll;	/*色彩表*/
	std::vector<PixelData24>	bmp24PixelData;	/*24位像素点信息*/
	std::vector<IMAGEDATA>		bmpData;		/*像素信息*/
};
#endif
