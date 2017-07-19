#include <iostream>
using namespace std;

// 移动赋值主要目的是为了将临时对象或者变量的生命周期变得更长
// 而这个临时变量的地址(内存)将被继续使用
// 但是如果使用的是一个已经存在的对象去移动赋值的话, 这个是不被允许的

// 换句话说, 就是临时的都是被允许使用的

class A
{
public:
	A(int a = 0)
	{
		this->a = a;
	}
	void operator=(A &&others)
	{
		this->a = others.a;
	}
	A(const A &&Ohter)  //移动构造函数
	{
		this->a = Ohter.a;
	}
	void visit()
	{
		cout << this->a << endl;
	}
private:
	int a;
};



int main(void)
{
	A a;
	A b(A(2));
	//A c(b);		// “A::A(const A &)”: 尝试引用已删除的函数    编译器已在此处生成“A::A”

	a.visit();
	b.visit();
	b = A(5);
	b.visit();
	system("pause");
	return 0;
}