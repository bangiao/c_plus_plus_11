#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
(1)  目标是 虚函数
	父类中一般用 final
	子类中一般用 override 
(2)
	final 防止子类重写
	override 防止子类重写的函数不在父类中
*/

class A
{
public:
	A() 
	{
		cout << "父类的构造函数" << endl;
	}
	virtual void print()
	{
		cout << typeid(A).name() << endl;
	}
	virtual void func1()
	{
		this->func();
	}
	void func() 
	{
		cout << "A:func" << endl;
	}
};

class B : public A
{
public:
	B() 
	{
		cout << "子类的构造函数" << endl;
	}
	virtual void print()
	{
		cout << typeid(B).name() << endl;
	}
	virtual void func1() override
	{
		this->func();
	}
	void func() 
	{
		cout << "B:func" << endl;
	}
protected:
private:
};

int main(void)
{
	A &a = B();

	a.func();
	a.func1();
	a.print();

	system("pause");
	return 0;
}