#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <thread>
#include <windows.h>
#include "memory"
using namespace std;

int g_num = 0;

void msg()
{
	MessageBox(0, TEXT("zhazha"), TEXT("Ti: "), MB_OK);
	++g_num;
	cout << g_num << " \n " << this_thread::get_id() << endl;
}
int main(void)
{
	thread t1(msg);
	thread t2(msg);

	t1.join();
	t2.join();

	system("pause");
	return 0;
}