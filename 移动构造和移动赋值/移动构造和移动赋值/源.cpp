#include <iostream>
#include <string>
using namespace std;

class Pointer
{
public:
	Pointer(const int i, const string &n)
	{
		mptr = new int[i];
		length = i;
		name = n;
		cout << "带参数构造函数\n";
		showID();
	}
	Pointer() : mptr(nullptr), length(0) 
	{ 
		cout << "无参数构造函数\n"; showID(); 
	}
	
	virtual ~Pointer()
	{
		cout << name + "析构函数\n";
		if (mptr)
			delete[] mptr;
		mptr = nullptr;
	}

	Pointer(const Pointer& s)
	{
		length = s.getlen();
		mptr = new int[length];
		name = s.name;
		cout << "复制构造函数\n";
		showID();
	}
	Pointer& operator=(const Pointer &s)
	{
		if (this == &s)
			return *this;
		if (mptr)
			delete[] mptr;
		length = s.getlen();
		mptr = new int[length];
		name = s.name;
		cout << "赋值运算符\n";
		showID();
		return *this;
	}

	//移动构造函数，参数s不能是const Pointer&& s，因为要改变s的成员数据的值
	Pointer(Pointer&& s)
	{
		length = s.getlen();
		mptr = s.getmptr();
		name = s.name + "_yidonggouzao";//调用移动构造函数时，加一个标记
		s.mptr = nullptr;
		cout << "移动构造函数\n";
		showID();
	}

	//移动赋值运算符
	Pointer& operator=(Pointer&& s)
	{
		cout << typeid(s).name() << endl;
		if (this == &s)
			return *this;
		if (mptr)
			delete[] mptr;
		length = s.getlen();
		mptr = s.mptr;
		name = s.name + "_yidongfuzhi";//调用移动赋值运算符时，加一个标记
		s.mptr = nullptr;
		cout << "移动赋值运算符\n";
		showID();
		return *this;
	}

	void showID()
	{
		cout << "长度：" << length << "  指针：" << mptr << "  名字：" << name << endl;
	}

	int getlen() const
	{
		return length;
	}

	int* getmptr()const
	{
		return mptr;
	}

private:
	int* mptr;
	int length;
	string name = "#NULL";//该参数用来标记不同的对象，c++11支持直接在类的数据成员定义处初始化
};

Pointer test()
{
	Pointer a(2, "test");
	return a;
}

int main(void)
{
	//加花括号是为了观察析构函数的调用
	{
		Pointer(4, "notname1");

		Pointer a1 = test();//调用移动构造函数，创建对象a1
		cout << "a1.showID():\n";
		a1.showID();

		Pointer a2;
		a2 = Pointer(5, "notname2");//调用移动赋值运算符

		Pointer a3(Pointer(7, "notname3"));//此处没有调用移动构造函数，也就是说Pointer(7, "notname3") 这个变量没有被立即销毁（即不是临时变量），也许是因为它有了名字a3，所以不是临时变量了

		cout << "a3.showID():\n";
		a3.showID();//验证a3确实是Pointer(7, "notname3")
	}

	cout << endl;
	system("pause");
	return 0;
}