#include <iostream>
using namespace std;

typedef char *pstring;

/* const��������˭? */
// const pstring �����const ���ε���  pstring ����  char * �������� ����һ��ָ�����
// const int *p �������ε��� const int ����ֵ 
// int  const * p ����������� const *p
// int * const p1  �������ε��� p1 ����ָ�����

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