#include <iostream>
#include <vector>
using namespace std;

// ��ֵ����
/*
1. ֻ�ܰ���һ����Ҫ���ٵĶ�����
2. �ӳ���ʱ�������������
*/

int add(const int &a, const int &b)
{
	return a + b;
}

int main(void)
{
	int i = 42;
	int &a = i;
//	int &&b = i;	//����ʼ����: �޷��ӡ�int��ת��Ϊ��int &&��
	int &&c = i + 42;
	const int &d = i;
	int && f = add(1, 2);
//	const int &&e = i;//����ʼ����: �޷��ӡ�int��ת��Ϊ��int &&��

	/*
		i: 00F7FA20
		a: 00F7FA20
		c: 00F7F9FC
		d: 00F7FA20
	*/
	cout << "i: " << &i << endl;
	cout << "a: " << &a << endl;
	cout << "c: " << &c << endl;
	cout << "d: " << &d << endl;

	vector<int> v1(100);
	int &r1 = v1[0];
	int &r2 = f;
	int &&r3 = v1[0] * add(1, 2);
	system("pause");
	return 0;
}