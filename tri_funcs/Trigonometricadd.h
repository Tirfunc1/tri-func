#pragma once

/*************************************************

Function:�����Ҽ��㺯��

Description:��Cordic�㷨��������Ƕȶ�Ӧ������ֵ������ֵ

Input:  beta:�Ƕ�ֵ

Output: �Ƕ�ֵ��Ӧ������ֵ������ֵ

Return:���ؽṹ�����������������Ա����������Ƕ�ֵ����õ�������ֵ������ֵ

Cordic�㷨���ö��ַ�˼����ת����v(1,0)��ʹ��ƽ�����Ľǣ�
			����ת��ɺ������v'����ϵ��Kn
			�õ��ĺ����꼴Ϊ����Ƕȵ�����ֵ�������꼴Ϊ����Ƕȵ�����ֵ
*************************************************/

#include<iostream>
#include"pch.h"
#include"tab.h"
#include"Trigonometricadd.h"
using namespace std;


struct Result Trigonometric(double beta)
{
	struct Result ret;
	ret.cosine = 1;
	ret.sine = 0;
	/*�ж�����beta�Ƿ���[-90��,90��]
	  ��������ͨ����beta��num��piʹ������[-90��,90��]������*/
	int num_pi = 0;
	while (beta < -90)
	{
		beta = beta + 180;
		num_pi = num_pi + 1;
	}
	while (beta > 90)
	{
		beta = beta - 180;
		num_pi = num_pi + 1;
	}

	double direction_of_rotation = 1;    //��ת�����־��1Ϊ��ʱ�룬-1Ϊ˳ʱ��
	double factor;                       //��ת�����е�Ԫ��
	double initial_angle = beta;         //��¼��ʼ����Ƕ�
	double poweroftwo = 1;               //1/2��n�η���nΪ��ת����
	double rotation_angle;               //������ת�Ƕ�
	double temp;                         //�ݴ����
	double v = 0;                        //��ת������ʼ�Ƕ�

	for (int i = 0; i < sizeof(angles) / sizeof(double); i++)
	{
		rotation_angle = angles[i];
		beta = initial_angle - v;
		if (beta < 0)
			direction_of_rotation = -1;
		else
			direction_of_rotation = 1;
		v = v + direction_of_rotation * rotation_angle;
		factor = direction_of_rotation * poweroftwo;
		temp = ret.cosine;
		//v'=v*��ת������ת����=[1,-factor;factor,1]
		ret.cosine = 1 * ret.cosine + (-factor) * ret.sine;
		ret.sine = factor * temp + 1 * ret.sine;
		poweroftwo = poweroftwo / 2;
	}
	ret.cosine = ret.cosine * Kn;
	ret.sine = ret.sine * Kn;
	/*���ڸ���ʼ��ʼ�Ƕȼ���num��pi���ж�num_pi����������ż��
	��Ϊ��������Ҫ�������Ϊ�෴��*/
	if ((num_pi % 2) != 0)
	{
		ret.sine = -ret.sine;
		ret.cosine = -ret.cosine;
	}
	return ret;
}

