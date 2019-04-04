/*************************
	数据基本处理
	2019/1/6
************************/
#ifndef _DATA_PROCESS_
#define _DATA_PROCESS_
#include "BmpProcess.h"
#include <vector>

int iGetBooleanArray(const BYTE rgb24ColorData, std::vector<int>  &colorBooleanArray);		/*对BYTE数处理得到各个位的数据*/
int iGetColorDataDec(const std::vector<int>  &colorBooleanArray, int &colorDataSum);		/*计算二维数组中的数得到十进制值*/

#endif
