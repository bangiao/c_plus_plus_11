#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
c++ 的手动内存池
	使用 限定 new 关键字限定在一片已经分配好的内存中
*/

const int N(5);
const int bufmax(512);
char buffer[bufmax] = { 0 };

int main(void)
{
	double *p1, *p2, *p3;

	for (int i = 0; i < 3; i++)
	{
		p1 = new double[N];
		p2 = new(buffer)double[N];
		p3 = new(buffer + N * sizeof(double))double[N];
		cout << "buffer: " << buffer << "  ";
		cout << "p1:" << p1 << "  ";
		cout << "p2: " << p2 << "  ";
		cout << "p3: " << p3 << endl;
		delete[]p1;
	}

	system("pause");
	return 0;
}