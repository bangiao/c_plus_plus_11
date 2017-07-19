#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class A
{
public:
	A(int a)
	{
		this->a = a;
	}
protected:
private:
	int a;
};

class B : public A
{
public:
	B()noexcept(true) : A(0)
	{
		this->b = 0;
		throw 1;
	}
protected:
private:
	int b;
};

int main(void)
{
	cout << "hello world" << endl;
	system("pause");
	return 0;
}