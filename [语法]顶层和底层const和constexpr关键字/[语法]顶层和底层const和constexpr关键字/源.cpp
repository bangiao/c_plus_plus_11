#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void)
{
	// what?
	// ���� const ����ָ: ָ���ǳ���,    
	// �ײ� const ����ָ: ָ��ָ��ı����ǳ���
	// ���� ָ������������ǿ�����,
	// ���Ϊ����Ļ�, const ���ε�����������
	// ���Ϊ�ײ�Ļ�, ָ���������ǹۿ�����ĳ��б� const ����

	int i = 10;
	// can
	int *const p1 = &i;// ���� const  ���� p1 ָ��   p1 ָ�벻�ܱ����¶���
	
	
	const int ci = 42;// ����Ƕ��� const ���α������ڴ�ռ�
	const int *p2 = &ci;// �����һ���ײ� const const ���� int �������ڴ�ռ�

	const int * const p3 = p2;// p3 ����ס, ���ڴ治�ɱ��޸�
	const int &r = ci;// �������� r

	i = ci;
	p2 = p3;

	// int *p = p3; // p3 ���ڴ�ռ��ǳ�����, p ָ����ڴ�ռ䲻�Ǳ���
	p2 = p3;
	p2 = &i;
	// int &r = ci; // ci �ǳ���
	const int &r2 = i;

	// how

	system("pause");
	return 0;
}