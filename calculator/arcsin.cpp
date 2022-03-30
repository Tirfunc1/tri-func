/* ************************************************

Function:反正弦计算函数

Description:根据公式 arcsin(x)=arctan(x/sqrt(1-x*x))计算输入正弦值对应的角度

Input:正弦值

Output:正弦值对应的角度

Return:正弦值对应的角度

************************************************ */

#include<iostream>
#include"tab.h"
#include"arctan.h"
#include"arcsin.h"
#include<math.h>
using namespace std;

double arcsin(double input_value_sin)
{
	if (input_value_sin > 1)
		cout << "输入值超出反正弦函数定义域" << endl;
	else if (input_value_sin == 1)
		input_value_sin = 999999999999;
	else
		input_value_sin = input_value_sin / sqrt(1 - input_value_sin * input_value_sin);
	double angle = arctan(input_value_sin);
	return angle;
}