#include <iostream>
using namespace std;

int main(void)
{
	int i = 10;
	const int *p = &i;
	auto p1 = p;
	// auto �����Եײ� const
	//*p1 = 20;

	int * const p2 = &i;
	auto p3 = p2;
	int a = 20;
	p3 = &a;

	system("pause");
	return 0;
}