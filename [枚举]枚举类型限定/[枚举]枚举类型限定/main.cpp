#include <iostream>
using namespace std;

// c++ 新语法, 枚举类型元素类型限定, 确保枚举元素类型仅在枚举中产生

enum color : char
{
	yellow = 'y',
	red = 1
};

int main(void)
{
	color c1;
	// 转换为枚举类型要求显式转换(static_cast、C 样式转换或函数样式转换)
	// c1 = 1;
	c1 = yellow;
	c1 = red;
	// 确保枚举元素类型仅在枚举中产生
	// c1 = 'A';

	system("pause");
	return 0;
}