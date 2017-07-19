#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
(1)  Ŀ���� �麯��
	������һ���� final
	������һ���� override 
(2)
	final ��ֹ������д
	override ��ֹ������д�ĺ������ڸ�����
*/

class A
{
public:
	A() 
	{
		cout << "����Ĺ��캯��" << endl;
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
		cout << "����Ĺ��캯��" << endl;
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