#include <iostream>
#include <string>
using namespace std;
//1. �������ں���������
const char *hello() { return __func__;  }
const char *world() { return __func__; }

// const char * hell()
// {
// 	static const char *__func__ = "hell";
// 	return __func__;
// }


//2. __func__ �ڽṹ����ʹ�þ��Ǵ�ӡ�ṹ�������

//3. __func__ ��������Ϊ�����Ĳ���ʹ��

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