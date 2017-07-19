#include <iostream>
#include <vector>
using namespace std;

// 右值引用
/*
1. 只能绑定在一个将要销毁的对象上
2. 延长临时对象的生命周期
*/

int add(const int &a, const int &b)
{
	return a + b;
}

int main(void)
{
	int i = 42;
	int &a = i;
//	int &&b = i;	//“初始化”: 无法从“int”转换为“int &&”
	int &&c = i + 42;
	const int &d = i;
	int && f = add(1, 2);
//	const int &&e = i;//“初始化”: 无法从“int”转换为“int &&”

	/*
		i: 00F7FA20
		a: 00F7FA20
		c: 00F7F9FC
		d: 00F7FA20
	*/
	cout << "i: " << &i << endl;
	cout << "a: " << &a << endl;
	cout << "c: " << &c << endl;
	cout << "d: " << &d << endl;

	vector<int> v1(100);
	int &r1 = v1[0];
	int &r2 = f;
	int &&r3 = v1[0] * add(1, 2);
	system("pause");
	return 0;
}