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
	// explicit �ؼ��־��ǽ�ֹ��, ���������ʹ��, 
	// ��Ϊ���������ʾ�Ĳ��ײ���ĸ�ֵ��ʽ���Ǻܺ�
	// A a = 10;
	A a1(10);
	A a2 = A(20);

	system("pause");
	return 0;
}