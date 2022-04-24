#pragma once

/* ************************************************

Function:�����Ҽ��㺯��

Description:���ݹ�ʽ arcsin(x)=arctan(x/sqrt(1-x*x))������������ֵ��Ӧ�ĽǶ�

Input:����ֵ

Output:����ֵ��Ӧ�ĽǶ�

Return:����ֵ��Ӧ�ĽǶ�

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