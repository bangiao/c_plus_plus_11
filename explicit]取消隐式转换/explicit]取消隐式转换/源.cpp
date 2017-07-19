#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class A
{
public:
	explicit A(int a)
	{
		this->a = a;
	}

// 	A(int a)
// 	{
// 		this->a = a;
// 	}
protected:
private:
	int a = 0;
};

int main(void)
{
	// explicit 关键字就是禁止了, 这种情况的使用, 
	// 因为这种情况显示的不伦不类的赋值方式不是很好
	// A a = 10;
	A a1(10);
	A a2 = A(20);

	system("pause");
	return 0;
}