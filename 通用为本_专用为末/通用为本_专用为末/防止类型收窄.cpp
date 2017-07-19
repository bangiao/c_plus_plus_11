#include <iostream>
using namespace std;

int main(void)
{
	const int x = 1024;
	const int y = 10;

	//char a = x;		// “初始化”: 从“const int”到“char”截断
	//char *b = new char(1024);//“初始化”: 从“int”到“char”截断

	//char c = { x };		//从“const int”转换到“char”需要收缩转换
	char d = { y };
	//unsigned char e{ -1 };		//从“int”转换到“unsigned char”需要收缩转换
	
	char e = y;

	float f{ 7 };
	//int g = { 0.2f };		//从“float”转换到“int”需要收缩转换
	//float i = 1.2l;		//“初始化”: 从“long double”到“float”截断
	system("pause");
	return 0;
}