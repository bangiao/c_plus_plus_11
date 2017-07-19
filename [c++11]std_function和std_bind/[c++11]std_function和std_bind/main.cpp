#include <iostream>
#include <functional> 
using namespace std;

// 一个不能绑定有this指针的函数一个则能
// std::function<函数的参数列表> 定义的类型就和函数指针的效果一样, 但是他的范围在 全局函数和类的静态成员函数中
// std::bind 也是和 函数指针类型一样, 但是他可以绑定 类的成员函数
// std::function<void (int)>  void 是返回值, int 是参数
// fp2 f = std::bind(&m_func3, this, std::placeholders::_1); 第一个是函数指针, 
//	第二个是函数参数 this 第三个是 参数占位符, 表示还有一个参数

typedef std::function<void()> fp;

void g_func()
{
	cout << "my name is g_func()" << endl;
}

class A
{
public:
	static void m_func1()
	{
		cout << "my name is static m_func1()" << endl;
	}

	void m_func2()
	{
		cout << "my name is m_func2()" << endl;
	}

	void m_func3(int a)
	{
		cout << "my name is m_func3 the value is " << a << endl;
	}

	virtual void m_virtual_fun()
	{
		cout << "this is parent func m_virtual_fun " << endl;
	}

	void init1()
	{
		fp fp1 = std::bind(&A::m_func2, this);
		fp1();
	}

	void init2()
	{
		typedef std::function<void(int)> fp2;
		fp2 f = std::bind(&A::m_func3, this, std::placeholders::_1);
	}

	void init3_virtual()
	{
		typedef std::function<void()> fp3;
		fp3 f3 = std::bind(&A::m_virtual_fun, this);
	}
};

class B : public A
{
public:
	using A::m_func1;
	using A::m_func2;
	using A::m_func3;
	using A::init1;
	using A::init2;
	virtual void m_virtual_fun()
	{
		cout << "child func m_virtual_func" << endl;
	}
protected:
private:
};

int main(void)
{
	A *a = new B;

	a->init1();
	a->init2();
	a->m_virtual_fun();		// 产生多态

	delete a;
	a = nullptr;

	// 绑定在全局函数, 和静态函数中
	fp p = fp(&A::m_func1);
	p();

	fp p2 = fp(&g_func);
	p2();

	system("pause");
	return 0;
}