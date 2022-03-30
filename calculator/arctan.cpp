/*************************************************

Function:反正切计算函数

Description:根据Cordic算法计算输入正切值对应的角度

Input:正切值

Output:正切值对应的角度

Return:正切值对应的角度

Cordic算法：输入正切值可以看作向量v(1,input_value_tan)对应的正切值，
            将向量v旋转一定度数，若旋转完成后v'纵坐标变为0
			则历次旋转角度之和即为输入正切值对应的角度
*************************************************/

#include<iostream>
#include"tab.h"
#include"arctan.h"
using namespace std;

double arctan(double input_value_tan)
{
	double y = input_value_tan;   //初始向量v的纵坐标
	double x = 1;                 //初始向量v的横坐标
	double x_new, y_new;          //旋转后向量v'的坐标
	double poweroftwo = 1;        //1/2的n次方，n为旋转次数
	double anglesum = 0;          //

	for (int i = 0; i < sizeof(angles) / sizeof(double); i++)
	{
		if (y > 0)
		{
			y_new = y - x * poweroftwo;
			x_new = x + y * poweroftwo;
			y = y_new;
			x = x_new;
			anglesum += angles[i];
			poweroftwo = poweroftwo / 2;
		}
		else if (y < 0)
		{
			y_new = y + x * poweroftwo;
			x_new = x - y * poweroftwo;
			y = y_new;
			x = x_new;
			anglesum -= angles[i];
			poweroftwo = poweroftwo / 2;
		}
		else
			break;
	}
	return anglesum;
}