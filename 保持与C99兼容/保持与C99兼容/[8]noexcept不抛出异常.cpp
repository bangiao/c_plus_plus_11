#include <iostream>
using namespace std;
//函数是否抛出异常
//1. noexecpt 的作用是不让抛出异常, 一抛出则调用 std::terminate 终止程序
//2. noexcept 有两种  noexcept (false) 和 noexecpt(true), 是否异常的意思
//3. noexcept 这个关键字
//4. 这个决定了c++编译器是否抛出异常情况


// 只要这个 T() 为真的话 true == noexcept(noexcept(true))
// template <class T>
// void func() noexcept (noexcept(T()))
// {
// 
// }
// 
// void Throw()
// {
// 	throw 1;
// }
// 
// void NoblockThrow()
// {
// 	Throw();
// }
// 
// void BlockThrow() noexcept
// {
// 	Throw();
// }
// 
// int main(void)
// {
// 	try
// 	{
// 		Throw();
// 	}
// 	catch (...)
// 	{
// 		cout << "found throw ." << endl;
// 	}
// 
// 	try
// 	{
// 		NoblockThrow();
// 	}
// 	catch (...)
// 	{
// 		cout << "throw is not blocked." << endl;
// 	}
// 
// 	try
// 	{
// 		BlockThrow();
// 	}
// 	catch (...)
// 	{
// 		cout << "throw is Block Throw" << endl;
// 	}
// 
// 	system("pause");
// 	return 0;
// }

struct A 
{
	~A() noexcept(false)
	{
		throw 1;
	}
};

struct B 
{
	~B() noexcept (false)
	{
		throw 2;
	}
};

struct C 
{
	B b;
};

void funcA() { A a; }
void funcB() { B b; }
void funcC() { C c; }

int main(void)
{
	try
	{
		funcB();
	}
	catch (...)
	{
		cout << "caught funcB." << endl;
	}
	try
	{
		funcC(); 
	}
	catch (...)
	{
		cout << "caught funcC." << endl;
	}
	try
	{
		funcA();
	}
	catch (...)
	{
		cout << "caught funcA." << endl;
	}

	system("pause");
	return 0;
}