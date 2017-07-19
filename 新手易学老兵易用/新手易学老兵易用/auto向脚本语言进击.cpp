#if 0
#include <iostream>
using namespace std;
#endif
// auto 实现的本质就是将类型匹配的时间延后就行了
/* auto 的优点 */
/*
	1. 此代码的可读性更好
	2. 可以避免一些类型声明的错误
	3. 自适应性, 一定程度上支持泛型编程
*/

#if 0
int main(void)
{
	auto str = "world\n";
	cout << str << endl;
	system("pause");
	return 0;
}
#endif

#if 0

auto foo()
{
	return 1.1;
}

int main(void)
{
	
	auto x = 1;
	auto y = foo();
	struct m 
	{
		int i = 0;
	}str;

	auto str1 = str;

// 	auto z;
// 	z = x;

	system("pause");
	return 0;
}

#endif 

// 用于数据类型比较复杂的情况下
#if 0
#include <iostream>
#include <vector>
#include <string>

void loopver1(std::vector<std::string> &s)
{
	std::vector<std::string>::iterator it = s.begin();

	for (; it != s.end(); it++)
	{
		// .....
	}
}

void loopver2(std::vector<std::string> &s)
{
	auto it = s.begin();

	for (; it != s.end(); it++)
	{
		// .....
	}
}

int main(void)
{
	
	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

class PI
{
public:
	double operator*(float v)
	{
		return (((double)val) * v);
	}
	const float val = 3.141592653f;
};

int main(void)
{
	auto radius = 1.7e10;
	PI pi;
	auto circumference = 2 * (pi * radius);
	cout << circumference << endl;
	system("pause"); 
	return 0;
} 
#endif

// auto 不能解决所有的数据溢出问题
#if 0
#include <iostream>
using namespace std;

int main(void)
{
	unsigned int a = 4294967295;
	unsigned int b = 1;


	auto c = a + b; // 这里的 c 还是unsigned int 类型

	cout << "a = " << a << "  b = " << b << "  c = " << c << endl;
	
	system("pause");
	return 0;
}
#endif

// auto 不能 auto = auto 类型和 auto a; 这些是不被允许的
#if 0
#include <iostream>
using namespace std;

template <class T1, class T2>
double sum(T1 &t1, T2 &t2)
{
	auto s = t1 + t2;
	return s;
}

int main(void)
{
	int a = 3;
	long b = 5;
	float c = 1.0f, d = 2.3f;
	auto e = sum<int, long>(a, b);
	auto f = sum<float, float>(c, d);
	cout << e << endl << f << endl;
	system("pause");
	return 0;
}

#endif


//使用auto定义高性能的宏定义, 可惜这个是错的

// #include <iostream>
// using namespace std;
// 
// #define MAX(a, b) ((a) > (b)) ? (a) : (b)
// #define MAX2(a, b) ({ \ 
// auto __a = (a); \
// auto __b = (b); \
// (__a > __b) ? __a : __b})
// 
// int main(void)
// {
// 	int m1 = MAX(1, 2);
// 	int m2 = MAX2(3, 1);
// 	system("pause");
// 	return 0;
// }


// 引用需要加上 & 必须的
#if 0
#include <iostream>
using namespace std;

int main(void)
{
	int x = 2;


	int *y = &x;
	auto * z = &x;
	auto a = &x;
	auto &b = x; // 引用需要加上 & 必须的
	auto c = x;

	system("pause");
	return 0;
}
#endif

#if 0

//decltype 是类型推导体验的另一部分

/* auto 的限制 */
//auto 不允许被使用在函数的参数中
//但是可以通过泛型编程实现 auto 参数类似功能
// auto 可以当做函数的返回值
//auto i = 0, j = 3.14f;// 这个就错了
// 这下面的这两个表达式其实都是可以的, 因为 常量 可以在 auto 里面被判断成 char 或者 int ...
//“var”: 非静态数据成员不能具有包含“auto”的类型

//“auto[3]”: 数组不能具有其中包含“auto”的元素类型
//"z": 数组初始化需要带括号的初始值设定项列表
//auto z[3] = x;
//但是 char z1[3] = x; 同样也是不行的


//模板参数不能为包含“auto”的类型
//Clas<auto> cc;

#include <iostream>
using namespace std;

//auto 不允许被使用在函数的参数中
//但是可以通过泛型编程实现 auto 参数类似功能
// void func(auto i = 1)
// {
// 	cout << i << endl;
// }

// auto 可以当做函数的返回值
auto func2(int u)
{
	return u;
}


// struct str 
// {
// 	auto var = 10;   //“var”: 非静态数据成员不能具有包含“auto”的类型
// };

template <class T>
class Clas
{
public:
	Clas() {};
protected:
private:
};

int main(void)
{
	//auto i = 0, j = 3.14f;// 这个就错了


	// 这下面的这两个表达式其实都是可以的, 因为 常量 可以在 auto 里面被判断成 char 或者 int ...
	auto i = new auto(1);
	auto y{ 1 };

	cout << "sizeof = " << sizeof(*i) << "  " << *i << endl;		// 4   1
	cout << "sizeof = " << sizeof(y) << "  " << y << endl;			// 4   1

	char x[3] = { 0 };
	//auto z[3] = x;
	//char z1[3] = x;

	Clas<int> c;
	//Clas<auto> cc;
	system("pause");
	return 0;
}

#endif

