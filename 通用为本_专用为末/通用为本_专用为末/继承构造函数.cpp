#include <iostream>
using namespace std;

// Ӧ�ó���
/*
	������Ĺ��캯���Ƚ϶�ʱ, ��������Ҫ�����ܶ��ʹ�û���Ĺ��캯��
	��Ҫʹ�ö���������Լ��Ĺ��캯����ʼ����Ա�б�
*/


// ��������������Ҫʹ�������f�����Ϳ���ʹ�� using �ڱ�ʾ�̳��˸���� ���� f
// ���ּ̳���ԭ�ⲻ���ļ̳�����


#if 0
struct Base
{
	void f(double i)
	{
		cout << "Base: " << i << endl;
	}
};

struct Derived : Base 
{
	using Base::f;
	void f(int i)
	{
		cout << "Derved: " << i << endl;
	}
};




int main(void)
{
	Derived d;
	d.f(1);
	d.f(1.1);
	system("pause");
	return 0;
}

#endif


// C++ 11
#if 0
struct A
{
	A(int i)
	{
		this->a = i;
		printf("i = %d", this->a);
	}
	A(double b, int i)
	{
		this->d = b;
		this->a = i;
		printf("i = %d, %f", this->a, this->d);
	}
	A(float f, int i, const char c)
	{
		this->a = i;
		this->f = f;
		this->c = c;
		printf("i = %d, %f, %c", this->a, this->f, this->c);
	}
	int a;
	double d;
	float f;
	char c;
};

struct B : A
{
	// �����ַ����Ļ� B������ A ���캯�������й��캯��, ����Ǽ̳л��๹�캯��
	// ����ͬʱȥ���� A �Ĺ��캯��, ��ʼ�� A �ĳ�Ա����
	using A::A;	
	int d{ 0 };
};

int main(void)
{
	B b(356);
	system("pause");
	return 0;
}
#endif

/*
	���ַ������ܷ�����ͻ
	������̳ж�����������»ᷢ����ͻ
*/

#if 0
struct A 
{
	A(int) {}
};

struct B 
{
	B(int) {}
};
struct C : A, B 
{
	using A::A;
	//��B::B��: ���캯���Ѽ̳��ԡ�A��
	//�μ���A::A��������
	using B::B;
	C(int) {}
};

int main(void)
{
	C c(1);
	system("pause");
	return 0;
}
#endif