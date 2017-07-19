#include <iostream>
using namespace std;

// typedef 不能给模板类进行取别名 , 但是 using 可以
// using 什么别名字 = 类的名字;

/*
	//模板类的语法
	template <class T>
	sing usingA  = class A<T>;
*/

template <class T>
class A
{
public:
	A(int a)
	{
		this->a = a;
	}
private:
	int a;
};

class B
{
public:
	B(int a)
	{
		this->a = a;
	}
private:
	int a{10};
};

template <class T>
using usingA  = class A<T>;

using usingB = class B;

// template <class T >
// typedef class A<T> typeA;

typedef class B typeB;




int main(void)
{
	usingA<int> a(10);

	usingB b(20);

	//typeA<int> f_a(30);

	typeB c(30);

	system("pause");
	return 0;
}