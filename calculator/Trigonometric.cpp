/*************************************************

Function:正余弦计算函数

Description:用Cordic算法计算输入角度对应的正弦值和余弦值

Input:  beta:角度值

Output: 角度值对应的正弦值和余弦值

Return:返回结构体变量，包含两个成员——由输入角度值计算得到的正弦值和余弦值

Cordic算法：用二分法思想旋转向量v(1,0)，使其逼近输入的角，
            则旋转完成后的向量v'乘以系数Kn
			得到的横坐标即为输入角度的余弦值，纵坐标即为输入角度的正弦值
*************************************************/

#include<iostream>
#include"tab.h"
#include"Trigonometric.h"
using namespace std;


struct Result Trigonometric(double beta)
{
	struct Result ret;
	ret.cosine = 1;
	ret.sine = 0;
	/*判断输入beta是否在[-90°,90°]
	  若不在则通过将beta加num次pi使其落在[-90°,90°]区间内*/
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

	double direction_of_rotation = 1;    //旋转方向标志，1为逆时针，-1为顺时针
	double factor;                       //旋转矩阵中的元素
	double initial_angle = beta;         //记录初始输入角度
	double poweroftwo = 1;               //1/2的n次方，n为旋转次数
	double rotation_angle;               //历次旋转角度
	double temp;                         //暂存变量
	double v = 0;                        //旋转向量初始角度
	
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
		//v'=v*旋转矩阵，旋转矩阵=[1,-factor;factor,1]
		ret.cosine = 1 * ret.cosine + (-factor) * ret.sine;
		ret.sine = factor * temp + 1 * ret.sine;
		poweroftwo = poweroftwo / 2;
	}
	ret.cosine = ret.cosine * Kn;
	ret.sine = ret.sine * Kn;
	/*由于给初始初始角度加了num个pi，判断num_pi是奇数还是偶数
	若为奇数，需要将结果变为相反数*/
	if ((num_pi %2)!=0)
	{
		ret.sine = -ret.sine;
		ret.cosine = -ret.cosine;
	}
	return ret;
}

