#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <thread>
using namespace std;

void func(int arg)
{
	for (int i = 0; i < 100; i++)
	{
		cout << "Ïß³Ì: " << i + 1 << endl;
	}
}

int main(void)
{
	thread _thread(func, 0);
	_thread.detach();
	for (int i = 0; i < 100; i++)
	{
		cout << "main: " << i + 1 << endl;
	}

	// _thread.join();
	
	system("pause");
	return 0;
}