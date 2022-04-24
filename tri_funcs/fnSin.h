#pragma once

#include "Trigonometricadd.h"
#define PI (3.1415926535898)

/**
 * @description: 
 * @param {bool} inputMode: 输入为角度时，inputMode为1；为弧度时，inputMode为0
 * @param {double} inputNum: 输入的x
 * @param {double} precision: 精度(可传参数)
 * @return {double} m_editoutput: 输出的sinx
 */
double fnSin(bool inputMode, double inputNum, double precision = 0.000000001)
{
	double m_editoutput;
	if (inputMode)
	{
		struct Result r = Trigonometric(inputNum);
		m_editoutput = r.sine;
	}
	else
	{
		inputNum = inputNum * 180 / pi;
		struct Result r = Trigonometric(inputNum);
		m_editoutput = r.sine;
	}
	return m_editoutput;
	
}