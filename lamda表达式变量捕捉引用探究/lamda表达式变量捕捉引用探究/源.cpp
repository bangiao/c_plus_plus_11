#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int g_num = 10;

int main(void)
{
	int num = 20;

	auto func = [&]() 
	{
		num++;
		cout << num << endl;
		g_num++;
		cout << g_num << endl;
	};

	func();

	cout << num << endl;
	cout << g_num << endl;

	system("pause");
	return 0;
}