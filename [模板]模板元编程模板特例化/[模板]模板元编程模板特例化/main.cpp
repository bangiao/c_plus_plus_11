#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// ��ģ��
template<int N>
struct Fib
{
	enum { Result = Fib<N - 1>::Result + N };
};

// // ��ȫ�ػ���
template <>
struct Fib<1>
{
	enum { Result = 1 };
};

int func(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n + func(n - 1);
	}
}

int main()
{
	int i = Fib<100>::Result;
	cout << i << endl;
	cout << func(4) << endl;
	system("pause");
	return 0;
}
