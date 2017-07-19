#include <iostream>
using namespace std;

// 应用场景
/*
	当基类的构造函数比较多时, 派生类想要尽可能多的使用基类的构造函数
	就要使用多个派生类自己的构造函数初始化成员列表
*/


// 下面这种情况如果要使用子类的f函数就可以使用 using 在表示继承了父类的 函数 f
// 这种继承是原封不动的继承下来


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
	// 用这种方法的话 B就有了 A 构造函数的所有构造函数, 这就是继承基类构造函数
	// 这里同时去调用 A 的构造函数, 初始化 A 的成员属性
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
	这种方法可能发生冲突
	派生类继承多个基类的情况下会发生冲突
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
	//“B::B”: 构造函数已继承自“A”
	//参见“A::A”的声明
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