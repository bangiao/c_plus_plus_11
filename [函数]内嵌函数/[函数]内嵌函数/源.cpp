#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <functional>
using namespace std;

/*
��һ������Ϊ��һ����������, ���������Ƕ����
*/

template <typename T, typename F>
T run(T val, F _func)
{
	return _func(val);
}

int main(void)
{
	// function<double(double)> ������Կ������� 
	// double(double)    �����double�Ƿ���ֵ, ()�����double�ǲ���
	std::function<double(double)> func1 = [](double u) {
		return u * 2;
	};

	double(*func)(double) = [](double u) {
		return u * 2;
	};

	// �ܽ�������������
	auto func2 = [](double u) {
		return u * 2;
	};


	cout << run(5.5, func1) << endl;
	cout << run(6.6, func) << endl;
	cout << run(7.7, func2) << endl;

	cout << typeid(func1).name() << endl;

	system("pause");
	return 0;
}