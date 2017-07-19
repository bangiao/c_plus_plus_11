#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <functional>
using namespace std;

/*
请一个函数为另一个函数办事, 这个就是内嵌函数
*/

template <typename T, typename F>
T run(T val, F _func)
{
	return _func(val);
}

int main(void)
{
	// function<double(double)> 这个可以看成这样 
	// double(double)    外面的double是返回值, ()里面的double是参数
	std::function<double(double)> func1 = [](double u) {
		return u * 2;
	};

	double(*func)(double) = [](double u) {
		return u * 2;
	};

	// 总结下来就是忘掉
	auto func2 = [](double u) {
		return u * 2;
	};


	cout << run(5.5, func1) << endl;
	cout << run(6.6, func) << endl;
	cout << run(7.7, func2) << endl;

	cout << typeid(func1).name() << endl;

	system("pause");
	return 0;
}