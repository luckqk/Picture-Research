/*************************
	数据基本处理 CPP
	2019/1/6
************************/
#include "DataProcess.h"


/*传入：保存数据的BYTE值
		保存转化后数据的vector
  作用：对于BYTE数据进行处理得到各个位的数据*/
int iGetBooleanArray(const BYTE rgb24ColorData, std::vector<int>  &colorBooleanArray )
{
	int num_tmp = 0;
	int loop;
	for (loop = 7;loop >= 0;loop--) {
		num_tmp = (rgb24ColorData >> loop) & 0x1;
		colorBooleanArray.push_back(num_tmp);
	}
	return EXIT_SUCCESS;
}

/*传入：保存数据的vector
  作用：通过计算二维数组中保存的数得到对应的十进制值*/
int iGetColorDataDec(const std::vector<int>  &colorBooleanArray, int &colorDataSum)
{
	int loop = 7;
	std::vector<int>::const_iterator it;
	for (it = colorBooleanArray.cbegin(); it!=colorBooleanArray.cend(); it++) {
		colorDataSum += (*it) * pow(2, loop);
		loop--;
	}
	return EXIT_SUCCESS;
}