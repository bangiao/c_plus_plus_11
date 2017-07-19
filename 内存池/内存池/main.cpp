#include <iostream>
using namespace std;

// char buf[1024] = { 0 };

// int main(int argc, char *args[])
// {
// 	char *p_buf = new (buf)char[10];
// 
// 	memcpy(p_buf, "zhazha", strlen("zhazha"));
// 
// 	cout << p_buf << endl;
// 	cout << buf << endl;
// 
// 	char *p_buf2 = new (buf + 10)char[10];
// 
// 	memcpy(p_buf2, "heihei", strlen("heihei"));
// 
// 	cout << p_buf2 << endl;
// 	cout << buf + 10 << endl;
// 
// 	system("pause");
// 	return 0;
// }

char *p = new char[100];

int main(int argc, char *args[])
{
	char *p_buf = new (p)char[10];

	memcpy(p_buf, "zhazha", strlen("zhazha") + 1);

	char *p_buf2 = new (p + 10)char[10];
	// 这种方式存在一些问题, 没有通过人的把控会出现巨大的bug
	//char *p_buf2 = new (p + 10)char[1000];

	memcpy(p_buf2, "heihei", strlen("heihei") + 1);

	cout << p << endl;

	cout << p_buf << endl;

	cout << p_buf2 << endl;

	if (NULL != p)
	{
		delete[]p;
		p = NULL;
	}
	system("pause");
	return 0;
}