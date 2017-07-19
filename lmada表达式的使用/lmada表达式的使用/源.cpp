#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
无返回值的 lamda [](){};
	lamda 表达式内部的变量和外部的变量是不同的作用域的
		[=] : (只读属性)
			这样的话, 就是去一次外部所有变量的值, 是值拷贝, 就是形参和实参的值拷贝
			但是这样的值, 在函数内部是不允许修改的, 他是常量值拷贝 [const =]
			这个时候可以使用 mutable 的时候就可以修改内部的变量了, 但是还是无法修改外部的变量
			只能修改内部的变量
		[&]: (可读, 可写)
			这个就是引用, 引用函数外部变量
*/

/*
有返回值的 lamda 表达式 []()->char{return (char )var; };
*/

int main()
{
	int n = 10;
	auto fun = [=]() mutable
	{
		n++;
		cout << n << endl;
	};

	fun();

	cout << n << endl;

	system("pause");
	return 0;
}

int g_num = 10;

int main2()
{
	int num = 300;

	auto _type = [=](int a, int b) ->int { return a + b + num; };

	cout << typeid(_type).name() << endl;

	cout << _type(1, 20) << endl;

	system("pause");
	return 0;
}

int main1(void)
{
	int num = 100;

	// 读 内部变量
	auto func1 =  [=](){
		cout << &num << ": " << num << endl;
		cout << g_num << endl;
	};

	// 读写 内部变量
	auto func2 = [&]() {
		num++;
		cout << &num << ": " << num << endl;
		cout << g_num << endl;
	};

	func2();
	cout << typeid(func2).name() << endl;
	func1();
	cout << typeid(func1).name() << endl;
	cout << &num << ": " << num << endl;

	system("pause");
	return 0;
}