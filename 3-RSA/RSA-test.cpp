//57118115 陈烨 密码学实验 RSA加密解密算法
//
#include<iostream>
#include<ctime>
#include<cmath>//加入数学库进行运算
using namespace std;
int prime[57118115] = { 0 };
int vis[57118115] = { 0 };
long long N, d, c = 1, pswd = 1, n, m = 57118115, e;
void sieve() //找出1-m之间的素数，存放在数组vis中
{
	int i, j, count = 0;
	for (i = 2; i <= m; i++)
	{
		if (!vis[i])
			prime[++count] = i;
		for (j = 1; j <= count && i * prime[j] <= m; j++)
		{
			vis[i * prime[j]] = 1;
			if (!(i % prime[j]))
				break;
		}
	}
}
int gcd(int a, int b)			//计算两个数的最大公因数
{
	if (b == 0) return a;
	gcd(b, a % b);
}
void generateN()
{
	int i, j;
	for (i = sqrt(m); i <= m; i++)		//找出一个比m大的n，使n为两素数和
		if (!vis[i])
		{
			for (j = i + 1; j <= m; j++)
				if (!vis[j])
				{
					n = i * j;
					N = (i - 1) * (j - 1);
					break;
				}
			break;
		}
}
void generateE()			//产生公钥e
{
	srand(time(NULL));
	while (1)
	{
		e = rand() % N;
		if (gcd(e, N) == 1) break;
	}
}
void calculateprivatekey()		//计算私钥d
{
	long long i;
	for (i = 1; i <= N; i++)
	{
		if ((i * N + 1) % e == 0)
		{
			d = (i * N + 1) / e;
			break;
		}
	}
}
void encryption()			//加密
{
	int i;

	for (i = 1; i <= e; i++)
	{
		c = (c * m) % n;
	}
	cout << "密文:" << c << endl;
}
void decryption()			//解密
{
	int i;
	for (i = 1; i <= d; i++)
	{
		pswd = (pswd * c) % n;
	}
	cout << "解密后的明文:" << pswd << endl;
}
int main()
{
	sieve();
	generateN();
	generateE();
	calculateprivatekey();
	cout << "公钥:(" << n << ',' << e << ')' << gcd(n, e) << endl;
	cout << "私钥:(" << n << ',' << d << ')' << d << endl;
	cout << "明文:" << m << endl;
	encryption();
	decryption();

	system("pause");
	return 0;

	
}
