#include <iostream>
using namespace std;
//�����Ƿ��׳��쳣
//1. noexecpt �������ǲ����׳��쳣, һ�׳������ std::terminate ��ֹ����
//2. noexcept ������  noexcept (false) �� noexecpt(true), �Ƿ��쳣����˼
//3. noexcept ����ؼ���
//4. ���������c++�������Ƿ��׳��쳣���


// ֻҪ��� T() Ϊ��Ļ� true == noexcept(noexcept(true))
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