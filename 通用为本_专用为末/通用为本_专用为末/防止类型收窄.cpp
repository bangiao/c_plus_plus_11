#include <iostream>
using namespace std;

int main(void)
{
	const int x = 1024;
	const int y = 10;

	//char a = x;		// ����ʼ����: �ӡ�const int������char���ض�
	//char *b = new char(1024);//����ʼ����: �ӡ�int������char���ض�

	//char c = { x };		//�ӡ�const int��ת������char����Ҫ����ת��
	char d = { y };
	//unsigned char e{ -1 };		//�ӡ�int��ת������unsigned char����Ҫ����ת��
	
	char e = y;

	float f{ 7 };
	//int g = { 0.2f };		//�ӡ�float��ת������int����Ҫ����ת��
	//float i = 1.2l;		//����ʼ����: �ӡ�long double������float���ض�
	system("pause");
	return 0;
}