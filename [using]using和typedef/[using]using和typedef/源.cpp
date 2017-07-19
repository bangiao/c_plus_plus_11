#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int add(int a, int b)
{
	return a + b;
}

typedef int(*FUNC_ADD)(int, int);
using FUNC_ADD1 = int(*)(int, int);

int main(void)
{
	
	system("pause");
	return 0;
}