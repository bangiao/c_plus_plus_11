#include <iostream>
using namespace std;

//1. #pragma 和 _Pragma 的效果是一样的
//2. _Pragma 不在是宏定义, 而是和 sizeof 一样的操作符
//3. 使用方法: _Pragma ("once"); // 效果和 #pragma once 一样
//4. 优点: 可以用在一些宏定义中
/*
	#define PRAGMA(x) _Pragma(#x)
*/

// int main(void)
// {
// 
// 
// 	system("pause");
// 	return 0;
// }