#include <iostream>
using namespace std;

typedef char *pstring;

/* const到底修饰谁? */
// const pstring 这里的const 修饰的是  pstring 就是  char * 整个整体 就是一个指针变量
// const int *p 这里修饰的是 const int 就是值 
// int  const * p 这个就是修饰 const *p
// int * const p1  这里修饰的是 p1 就是指针变量

int main(void)
{
	const pstring cstr = 0;// char * const cstr = 0;
	const pstring *ps;
	const char *cstr1 = 0;

	int i = 10;
	*cstr = i;

	system("pause");
	return 0;
}