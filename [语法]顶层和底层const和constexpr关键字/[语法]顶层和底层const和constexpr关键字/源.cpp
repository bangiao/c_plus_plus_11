#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void)
{
	// what?
	// 顶层 const 就是指: 指针是常量,    
	// 底层 const 就是指: 指针指向的变量是常量
	// 就像 指针就是人造卫星看城市,
	// 如果为顶层的话, const 修饰的是人造卫星
	// 如果为底层的话, 指从人造卫星观看下面的城市被 const 修饰

	int i = 10;
	// can
	int *const p1 = &i;// 顶层 const  修饰 p1 指针   p1 指针不能被重新定向
	
	
	const int ci = 42;// 这个是顶层 const 修饰变量的内存空间
	const int *p2 = &ci;// 这个是一个底层 const const 修饰 int 变量的内存空间

	const int * const p3 = p2;// p3 被定住, 切内存不可被修改
	const int &r = ci;// 常量引用 r

	i = ci;
	p2 = p3;

	// int *p = p3; // p3 的内存空间是常量的, p 指针的内存空间不是变量
	p2 = p3;
	p2 = &i;
	// int &r = ci; // ci 是常量
	const int &r2 = i;

	// how

	system("pause");
	return 0;
}