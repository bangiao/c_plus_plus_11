#include <iostream>
#include <string>
using namespace std;
//1. 返回所在函数的名字
const char *hello() { return __func__;  }
const char *world() { return __func__; }

// const char * hell()
// {
// 	static const char *__func__ = "hell";
// 	return __func__;
// }


//2. __func__ 在结构体中使用就是打印结构体的名称

//3. __func__ 不可以作为函数的参数使用

struct TestStrct 
{
	TestStrct() : name(__func__)
	{

	}
	const char *name;
};
// 
// int main(void)
// {
// 	cout << hello() << world() << endl;
// 	struct TestStrct temp;
// 	cout << temp.name << endl;
// 	system("pause");
// 	return 0;
// }