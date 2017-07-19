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


	// 这里面的 [] 这个是捕获上文的变量
	// () 是看 for_each 这个函数的第三个参数的函数指针是否有参数
	// 而这个lamda函数的 res 如果使用的是 [=] 捕获这是赋值捕获 这个不影响外部的res
	// [&] 就是引用变量 , 在 {} 修改的话可以影响外部 res
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