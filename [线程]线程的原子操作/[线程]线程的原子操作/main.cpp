#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

/*
	线程在修改资源的时候会copy一份副本进行修改, 等待修改完毕再还原回去
*/

std::mutex g_mutex;
int num = 0;

void func(int arg)
{
	g_mutex.lock();
	for (int i = 0; i < 500000; i++)
	{
		num ++;
	}
	g_mutex.unlock();
}


int main(void)
{
	thread _thread(func, 0);
	thread _thread2(func, 0);
	_thread.join();
	_thread2.join();
	cout << num << endl;
	system("pause");
	return 0;
}