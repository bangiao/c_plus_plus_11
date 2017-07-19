#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>

// ·ºÐÍ Lambda

auto func1(int a, int b)
{
	return a + b;
}

// auto func2(auto a, auto b)
// {
// 
// }

int main(void)
{
	int a = 10;

	auto func{ [=](auto a, auto b) {
		return a + b;
	} };

	double sum1{ func(10.1, 20.2) };

	std::cout << sum1 << std::endl;

	sum1 = func(10, 20) ;

	std::cout << sum1 << std::endl;

	system("pause");
	return 0;
}