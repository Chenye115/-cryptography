#include <iostream>
#include<cmath>
#include<stdlib.h>
#include<time.h>
using namespace std;

//判断两个数是否互素
int IsPrime(int a, int b)
{
	int temp;
	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}

	if (a == 1)
		return 1;
	else
		return 0;
}

//得到欧拉函数的值和取值集合
void Euler(int n, int* s, int& sum)
{
	int i, flag;
	for (i = 1; i < n; i++)
	{
		flag = IsPrime(i, n);
		if (flag == 1)
		{
			s[sum] = i;
			sum++;
		}
	}
}

//冒泡排序
void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

//快速幂取余实现(x^y%n)
int power(long int x, long int y, long int n)
{
	long int t = 1;
	while (y > 0)
	{
		if (y % 2 == 1)
		{
			y -= 1;
			t = t * x % n;
		}
		else {
			y /= 2;
			x = x * x % n;
		}
	}
	return t % n;
}

//根据互素集合利用遍历的方法求本原根
void root(int n, int sum, int s[])
{
	int i, j;
	int flag[100], k;
	for (i = 0; i < sum; i++)
	{
		k = 0;
		for (j = 1; j < sum + 1; j++)
		{
			//这里要利用快速幂取余，否则数值太大会溢出
			flag[j - 1] = power(s[i], j, n);
		}
		bubbleSort(flag, sum);

		for (j = 0; j < sum; j++)
		{
			if (flag[j] != s[j])
				k = 1;
		}
		if (k == 0)
			cout << s[i] << " ";
	}
}


//判断素数
bool is_prime(int number)
{
	int i;
	for (i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)
			return false;
	}
	if (i > sqrt(number))
		return true;

}

int main()
{
	int a, p;//
	int Xa, Xb;//随机生成的整数
	int Ya, Yb;//
	int KeyA, KeyB;//密钥
	

	/*
	srand((unsigned)time(NULL));//随机时间定义种子
	while (1)
	{

		p = 2 + (rand() % 95);//控制产生的随机数在2~97之间
		if (is_prime(p))
		{
			cout << "随机生成的素数p=" << p << endl;
			break;
		}
		else
			continue;
	}//产生随机素数p
	*/
	cout << "输入素数 p" << endl;
	cin >> p;





	cout << endl;
	int sum = 0;
	int s[100];
	Euler(p, s, sum);
	root(p, sum, s);//得到p的所有本原根
	cout << "输入p的本原根之一: " << endl;
	int temp;
	cin >> temp;//输入的值必须是本原根
	a = temp;

	/*
	while (1) {
		Xa = 2 + rand() % 30;//控制产生的随机数在2~29之间
		Xb = 2 + rand() % 30;//控制产生的随机数在2~29之间
		if (Xa != Xb)
		{
			cout << "随机生成的数a=" << Xa << endl;
			cout << "随机生成的数b=" << Xb << endl;
			break;
		}
		else
			continue;
	}//产生随机数
	*/

	cout << "a b" << endl;
	cin >> Xa >> Xb;
	cout << endl;


	Ya = a;
	for (int i = 0; i < Xa; i++)
	{
		Ya = (Ya % p) * a;

	}
	Ya = Ya % p;

	Yb = a;
	for (int i = 0; i < Xb; i++)
	{

		Yb = (Yb % p) * a;
	}
	Yb = Yb % p;

	cout << "KA=" << Ya << " KB=" << Yb << endl;

	KeyA = Yb;
	for (int i = 0; i < Xa; i++)
	{
		KeyA = (KeyA % p) * Yb;
	}
	KeyA = KeyA % p;

	KeyB = Ya;
	for (int i = 0; i < Xb; i++)
	{
		KeyB = (KeyB % p) * Ya;
	}
	KeyB = KeyB % p;


	cout << "KeyA=" << KeyA << " KeyB=" << KeyB << endl;
	cout << "解密成功！" << endl;
	return main();
	system("pause");
}