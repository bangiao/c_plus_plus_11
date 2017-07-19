#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <functional>
using namespace std;

struct Struct
{
	void func1(int a)
	{
		cout << a << endl;
	}

	void func2(int a, int b)
	{
		cout << a << endl;
		cout << b << endl;
	}

	void func3(int a, int b, int c)
	{
		cout << a << endl;
		cout << b << endl;
		cout << c << endl;
	}
};

int main(void)
{
	Struct s1;

	int n = 5;
	auto func = bind(&Struct::func1, &s1, std::placeholders::_1);
	func(10);
	cout << typeid(func).name() << endl;

	system("pause");
	return 0;
}