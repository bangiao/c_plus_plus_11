#include <iostream>
using namespace std;

int main(void)
{
	static int i = 0;
	const int ci = 0;
	const int *p1 = &ci;
//	int * const p2 = &ci;
	int *const p2 = &i;
//	constexpr int *p3 = &ci;
	constexpr int *p3 = &i;

	decltype(i) a = 10;
	cout << typeid(a).name() << endl;

	//decltype(ci) ci2 = 0;
	//ci2 = 1;

	//decltype(p1) p5 = 0;
	//p5 = 10;

	//decltype(p2) p6 = &i;
	//int j = 20;
	//p6 = &j;

	system("pause");
	return 0;
}