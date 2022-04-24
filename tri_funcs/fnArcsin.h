#pragma once

/* ************************************************

Function:反正弦计算函数

Description:根据公式 arcsin(x)=arctan(x/sqrt(1-x*x))计算输入正弦值对应的角度

Input:正弦值

Output:正弦值对应的角度

Return:正弦值对应的角度

************************************************ */

#include<iostream>
#include"../calculator/pch.h"
#include"tab.h"
#include"fnArctan.h"
#include"fnArcsin.h"
#include<math.h>
using namespace std;

double fnArcsin(bool inputMode, double input_value_sin, double precision = 0.000000001)
{
	if (input_value_sin == 1)
		input_value_sin = 999999999999;
	else
		input_value_sin = input_value_sin / sqrt(1 - input_value_sin * input_value_sin);
	double angle = fnArctan(inputMode, input_value_sin);

	if (inputMode) {
	}
	else {
		angle = angle * pi / 180;
	}
	return angle;
}