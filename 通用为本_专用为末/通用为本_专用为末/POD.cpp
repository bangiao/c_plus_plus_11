#include <iostream>
using namespace std;
/*
啥是POD类型？
POD全称Plain Old Data。通俗的讲，一个类或结构体通过二进制拷贝后还能保持其数据不变，那么它就是一个POD类型。

平凡的定义
1.有平凡的构造函数
2.有平凡的拷贝构造函数
3.有平凡的移动构造函数
4.有平凡的拷贝赋值运算符
5.有平凡的移动赋值运算符
6.有平凡的析构函数
7.不能包含虚函数
8.不能包含虚基类
*/



//平凡的定义
#if 0
class A { A() {} };
class B { B(B&) {} };
class C { C(C&&) {} };
class D { D operator=(D&) {} };
class E { E operator=(E&&) {} };
class F { ~F() {} };
class G { virtual void foo() = 0; };
class H : G {};
class I {};

int main(void)
{
	
	std::cout << std::is_trivial<A>::value << std::endl;  // 有不平凡的构造函数
	std::cout << std::is_trivial<B>::value << std::endl;  // 有不平凡的拷贝构造函数
	std::cout << std::is_trivial<C>::value << std::endl;  // 有不平凡的拷贝赋值运算符
	std::cout << std::is_trivial<D>::value << std::endl;  // 有不平凡的拷贝赋值运算符
	std::cout << std::is_trivial<E>::value << std::endl;  // 有不平凡的移动赋值运算符
	std::cout << std::is_trivial<F>::value << std::endl;  // 有不平凡的析构函数
	std::cout << std::is_trivial<G>::value << std::endl;  // 有虚函数
	std::cout << std::is_trivial<H>::value << std::endl;  // 有虚基类

	std::cout << std::is_trivial<I>::value << std::endl;  // 平凡的类

	system("pause");
	return 0;
}

#endif


/*
标准布局的定义

1.所有非静态成员有相同的访问权限
2.继承树中最多只能有一个类有非静态数据成员
3.子类的第一个非静态成员不可以是基类类型
4.没有虚函数
5.没有虚基类
6.所有非静态成员都符合标准布局类型
*/

class A
{
private:
	int a;
public:
	int b;
};

class B1
{
	static int x1;
};

class B2
{
	int x2;
};

class B : B1, B2
{
	int x;
};

class C1 {};
class C : C1
{
	C1 c;
};

class D { virtual void foo() = 0; };
class E : D {};
class F { A x; };

int main(void)
{
	std::cout << std::is_standard_layout<A>::value << std::endl;  // 违反定义1。成员a和b具有不同的访问权限
	std::cout << std::is_standard_layout<B>::value << std::endl;  // 违反定义2。继承树有两个(含)以上的类有非静态成员
	std::cout << std::is_standard_layout<C>::value << std::endl;  // 违反定义3。第一个非静态成员是基类类型
	std::cout << std::is_standard_layout<D>::value << std::endl;  // 违反定义4。有虚函数
	std::cout << std::is_standard_layout<E>::value << std::endl;  // 违反定义5。有虚基类
	std::cout << std::is_standard_layout<F>::value << std::endl;  // 违反定义6。非静态成员x不符合标准布局类型

	system("pause");
	return 0;
}
