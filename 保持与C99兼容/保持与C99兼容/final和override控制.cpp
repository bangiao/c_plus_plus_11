#include <iostream>
using namespace std;

//1. final 关键字的功能就是将标记的类或者虚函数无法被重写

//(1) “D1”: 无法从“B1”继承，因为它已被声明为“final”
// class B1 final
// {
// };
// class D1 : B1
// {
// };


//(2) “B2::f”: 声明为“final”的函数无法被“D2::f”重写
// struct B2 
// {
// 	virtual void f() final = 0;
// };
// 
// struct D2 : B2 
// {
// 	void f() {}
// };

/*
	2. 开发 D3 的程序员真的想重写B3::f函数吗？还是说，
		他只是不小心写了个与父类同名的函数，
		却在不经意间导致了覆盖？为了避免这种错误，
		C++ 11 引入了override关键字（多么像 C# 啊！）
 */

struct B4 
{
	virtual void g(int) {}
};

struct D4 : B4 
{
	void g(int) override {}
	//void g(double) override {}  // 虽然想要进行 override 的操作, 但是实际上父类并没有这个函数
};

int main(void)
{
	B4 b;
	b.g(12);

	system("pause");
	return 0;
}
