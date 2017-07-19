#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
�޷���ֵ�� lamda [](){};
	lamda ���ʽ�ڲ��ı������ⲿ�ı����ǲ�ͬ���������
		[=] : (ֻ������)
			�����Ļ�, ����ȥһ���ⲿ���б�����ֵ, ��ֵ����, �����βκ�ʵ�ε�ֵ����
			����������ֵ, �ں����ڲ��ǲ������޸ĵ�, ���ǳ���ֵ���� [const =]
			���ʱ�����ʹ�� mutable ��ʱ��Ϳ����޸��ڲ��ı�����, ���ǻ����޷��޸��ⲿ�ı���
			ֻ���޸��ڲ��ı���
		[&]: (�ɶ�, ��д)
			�����������, ���ú����ⲿ����
*/

/*
�з���ֵ�� lamda ���ʽ []()->char{return (char )var; };
*/

int main()
{
	int n = 10;
	auto fun = [=]() mutable
	{
		n++;
		cout << n << endl;
	};

	fun();

	cout << n << endl;

	system("pause");
	return 0;
}

int g_num = 10;

int main2()
{
	int num = 300;

	auto _type = [=](int a, int b) ->int { return a + b + num; };

	cout << typeid(_type).name() << endl;

	cout << _type(1, 20) << endl;

	system("pause");
	return 0;
}

int main1(void)
{
	int num = 100;

	// �� �ڲ�����
	auto func1 =  [=](){
		cout << &num << ": " << num << endl;
		cout << g_num << endl;
	};

	// ��д �ڲ�����
	auto func2 = [&]() {
		num++;
		cout << &num << ": " << num << endl;
		cout << g_num << endl;
	};

	func2();
	cout << typeid(func2).name() << endl;
	func1();
	cout << typeid(func1).name() << endl;
	cout << &num << ": " << num << endl;

	system("pause");
	return 0;
}