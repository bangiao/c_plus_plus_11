#include <iostream>
using namespace std;

class A
{
public:
	A() : d(new int(0)) {}
	A(A &h) : d(new int(*h.d)) {}
	~A()
	{
		delete d;
	}
	int *d;
};

int main(void)
{
	A a;
	A b(a);

	cout << a.d << endl;
	cout << b.d << endl;
	
	system("pause");
	return 0;
}