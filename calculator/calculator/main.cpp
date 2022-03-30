/*************************************************

Function:主函数

Description:调用各个功能函数，实现三角函数与反三角函数计算器的功能

************************************************ */
#include<iostream>
#include"tab.h"
#include"Trigonometric.h"
#include"arctan.h"
#include"menu.h"
#include"arcsin.h"
using namespace std;
int main()
{
	cout.precision(10);
	int key_select = 100;//功能选择键
	while (true)
	{
		showMenu();
		cin >> key_select;
		switch (key_select)
		{
		case 1:
		{
			int key_unit;//单位选择标志
			cout << "请选择您希望使用的单位：1.角度     2.弧度" << endl;
			cin >> key_unit;
			double beta;
			if (key_unit == 1)
			{
				cout << "请输入角度beta" << endl;
				cin >> beta;
				//调用正余弦计算函数，因为返回值有正弦值和余弦值两项，因此用结构体变量接受返回值
				struct Result r = Trigonometric(beta);
				cout << "sin(beta)=" << r.sine << endl;
				cout << "cosin(beta)=" << std::fixed << r.cosine << endl;
			}
			else if (key_unit == 2)
			{
				cout << "请输入弧度值beta" << endl;
				cin >> beta;
				//若选择的单位为弧度，则先将其转换为角度
				beta = beta * 180 / pi;
				struct Result r = Trigonometric(beta);
				cout << "sin(beta)=" << r.sine << endl;
				cout << "cosin(beta)=" << std::fixed << r.cosine << endl;
			}
			else
				cout << "请选择正确的单位" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			int key_unit;
			cout << "请选择您希望使用的单位：1.角度     2.弧度" << endl;
			cin >> key_unit;
			if (key_unit == 1 || key_unit == 2)
			{
				double numy;
				cout << "请输入正切值：" << endl;
				cin >> numy;
				double angle = arctan(numy);
				if (key_unit == 1)
					cout << "对应角度为：" << angle << endl;
				else
				{
					angle = angle / 180 * pi;
					cout << "对应弧度为：" << angle << endl;
				}
			}
			else
				cout << "请选择正确的单位" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			int key_unit;
			cout << "请选择您希望使用的单位：1.角度     2.弧度" << endl;
			cin >> key_unit;
			if (key_unit == 1 || key_unit == 2)
			{
				double numy;
				cout << "请输入正弦值：" << endl;
				cin >> numy;
				double angle = arcsin(numy);
				if (key_unit == 1)
					cout << "对应角度为：" << angle << endl;
				else
				{
					angle = angle / 180 * pi;
					cout << "对应弧度为：" << angle << endl;
				}
			}
			else
				cout << "请选择正确的单位" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 0:
		{
			system("pause");
			return 0;
		}
		}
	}
}