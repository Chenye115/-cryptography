//57118115 陈烨
//密码学实验
//扩展欧几里得算法
//#include "pch.h"
#include <iostream>
#include<cmath>
#include<cstdio>
using namespace std;


int exgcd(int a, int b, int& x, int& y)//扩展欧几里得算法
{
	if (b == 0)
	{
		x = 1; y = 0;
		return a;  //到达递归边界开始向上一层返回
	}
	int r = exgcd(b, a % b, x, y);
	int temp = y;    //把x y变成上一层的
	y = x - (a / b) * y;
	x = temp;
	return r;     //得到a b的最大公因数
}

int multi(int a, int b, int& x, int& y)
{
	int gcd = exgcd(a, b, x, y);
	if (gcd != 1)//说明不存在乘法逆元
	{
		cout << "乘法逆元不存在！" << endl;
		return -1;
	}
	else
	{
		return (1 - b * y) / a;
	}
}

int main()
{
	int a, b, temp, x, y;
	cout << "请输入要求的第一个数a：";
	cin >> a;
	cout << "请输入要求的第一个数b：";
	cin >> b;
	if (a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}//交换顺序，大在前
	cout << "最大公因数为：" << exgcd(a, b, x, y) << endl;
	cout << a << "关于1模" << b << "的乘法逆元为：" << multi(a, b, x, y) << endl;
	cout << b << "关于1模" <<a << "的乘法逆元为：" << multi(b, a, x, y) << endl;
	return main();
	system("pause");
	return 0;
}