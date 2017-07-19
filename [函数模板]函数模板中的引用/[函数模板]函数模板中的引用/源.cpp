#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <functional>
using namespace std;

template <typename T>
//void func(T &arg)
void func(T arg)
{
	arg++;
}

int main(void)
{
	int arg = 0;

	//func<int>(arg);
	//func(arg);

	func(std::ref(arg));

	cout << arg << endl;
	system("pause");
	return 0;
}