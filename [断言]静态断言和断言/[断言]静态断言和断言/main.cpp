#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
using namespace std;

int main(void)
{
	int a = 10;

	assert(a == 10);
	static_assert(sizeof(a) > 3, "cuowu");

	cout << a << endl;

	system("pause");
	return 0;
}