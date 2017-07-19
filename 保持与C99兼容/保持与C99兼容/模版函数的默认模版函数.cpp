#include <iostream>
using namespace std;

// 在 C++ 98 里面不支持模板函数传递默认参数

template <class T = int, int c = 10>
T add(const T &a, const T &b)
{
	return a + b + c;
}

template <typename T = int, int c = 10>
class tmp
{
public:
	tmp(T a = 20, T b = 30)
	{
		this->a = a + c;
		this->b = b - c;
	}
	T add(const T &a, const T &b)
	{
		return a + b;
	}
	T &getA()
	{
		return this->a;
	}
	T &getB()
	{
		return this->b;
	}
private:
	T a, b;
};

int main(void)
{
	int a = 10;
	int b = 20;

	int sum = 0;
	sum = add<int, 20>(a, b);
	cout << sum << endl;
	sum = add(a, b);
	cout << sum << endl;

	tmp<int> t;

	sum = t.add(t.getA(), t.getB());
	cout << sum << endl;
	system("pause");
	return 0;
}