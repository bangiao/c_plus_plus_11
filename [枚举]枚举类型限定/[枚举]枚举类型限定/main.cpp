#include <iostream>
using namespace std;

// c++ ���﷨, ö������Ԫ�������޶�, ȷ��ö��Ԫ�����ͽ���ö���в���

enum color : char
{
	yellow = 'y',
	red = 1
};

int main(void)
{
	color c1;
	// ת��Ϊö������Ҫ����ʽת��(static_cast��C ��ʽת��������ʽת��)
	// c1 = 1;
	c1 = yellow;
	c1 = red;
	// ȷ��ö��Ԫ�����ͽ���ö���в���
	// c1 = 'A';

	system("pause");
	return 0;
}