#include <iostream>
#include <cassert>
using namespace std;

// ��̬����, ���ǽ�һ������ֵ������ҪΪ����б�ʽ���������, �����ų�������ϳ��ֵ��߼��ϲ�Ӧ�õ����
// 
// char *Array_alloc(int n)
// {
// 	assert(n > 0);
// 	return new char[n];
// }
// 
// int main(void)
// {
// 	char *a = Array_alloc(0);
// 
// 	delete[]a;
// 
// 	system("pause");
// 	return 0;
// }

// enum FeatureSupports
// {
// 	C99 = 0x0001,
// 	ExtInt = 0x0002,
// 	SAssert = 0x0004,
// 	NoExcept = 0x0008,
// 	SMAX = 0x0010
// };
// 
// struct Compiler 
// {
// 	const char *name;
// 	int spp;
// };
// 
// int main(void)
// {
// 	assert((SMAX - 1) == (C99 | ExtInt | SAssert | NoExcept));
// 	Compiler a = { "abc", (C99 | SAssert) };
// 
// 	if (a.spp & C99)
// 	{
// 
// 	}
// 
// 	system("pause");
// 	return 0;
// }

// ���Եı���, ���� if xxxxx


template <class T, class U>
int bit_copy(T &a, U &b)
{
	assert(sizeof(a) == sizeof(b));
	memcpy(&a, &b, sizeof(b));	
	return 0;
}

int main()
{
	int a = 0x2468;
	double b;
	bit_copy(a, b);
	system("pause");
	return 0;
}