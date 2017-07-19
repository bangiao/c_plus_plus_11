#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	vector<int> myarr;

	myarr.push_back(11);
	myarr.push_back(22);
	myarr.push_back(33);

	int res = 0;


	// ������� [] ����ǲ������ĵı���
	// () �ǿ� for_each ��������ĵ����������ĺ���ָ���Ƿ��в���
	// �����lamda������ res ���ʹ�õ��� [=] �������Ǹ�ֵ���� �����Ӱ���ⲿ��res
	// [&] �������ñ��� , �� {} �޸ĵĻ�����Ӱ���ⲿ res
	auto func = for_each(myarr.begin(), myarr.end(), [&](int x) {
		res += x;
	});

// 	auto func = for_each(myarr.begin(), myarr.end(), [&res](int x) {
// 		res += x;
// 	});

	cout << typeid(func).name() << endl;
	cout << res << endl;

	system("pause");
	return 0;
}