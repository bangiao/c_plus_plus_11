#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory>
using namespace std;

int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		char *p1 = new char[1024];
		shared_ptr<char> p2(p1);
		memcpy(p1, "zhazha", 7);
		cout << p2 << endl;
	}
	system("pause");
	return 0;
}