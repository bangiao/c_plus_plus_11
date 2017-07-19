#include <iostream>
using namespace std;

int add(const int &a, const int &b)
{
	return a + b;
}

int main(void)
{
	/* 常量表达式 */
	const int max_file = 27;	// T
	const int limit = max_file + 1;//T
	const int sz = add(1, 2);//F
	/* constexpr */
	constexpr int max_file2 = 27;
	constexpr int linit2 = max_file + 1;
	// error C2131: 表达式的计算结果不是常数
	// note: 对未定义的函数或为未声明为“constexpr”的函数的调用导致了故障
	// note: 请参见“add”的用法
	//constexpr int sz2 = add(1, 2);

	/* 指针和constexpr */
	const int *p = nullptr;
	constexpr int *p2 = nullptr;// == int *const p2;
	int i = 10;
	const int *p3 = &i;
	constexpr int *p4 = &i;
	cout << *p4 << " " << p4 << endl;
	system("pause");
	return 0;
}