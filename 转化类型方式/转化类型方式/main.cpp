#include <iostream>
using namespace std;

int main(void)
{
	double a = 0;
	const int i = 10;
	const int j = 20;
	a = static_cast<double>(i) / static_cast<double>(j);
	cout << a << endl;
	const int *p = &i;
	int *p1 = const_cast<int *>(p);
	//*p = 30;
	*p1 = 20;
	cout << i << endl;
	cout << &i << endl;
	cout << *p << endl;
	cout << p << endl;
	cout << *p1 << endl;
	cout << p1 << endl;
	system("pause");
	return 0;
}