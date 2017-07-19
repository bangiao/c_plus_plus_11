#if 0
#include <iostream>
using namespace std;

int main(void)
{
	int girls = 3, boys = 4;
	auto totalChild = [](int x, int y)->int { return x + y; };
	cout << totalChild(girls, boys) << endl;
	cout << typeid(totalChild).name() << endl;
	system("pause");
	return 0;
}
#endif 

#if 0

#include <iostream>
using namespace std;

int main(void)
{
	int boys = 4, girl = 3;
	auto totalChild = [girl, &boys]()->int { return boys + girl; };
	cout << totalChild() << endl;
	cout << typeid(totalChild).name() << endl;
	system("pause");
	return 0;
}
#endif 
#if 0
#include <iostream>
using namespace std;

int main(void)
{
	int boys = 4, girl = 3;
	auto totalChild = [=]()->int { return boys + girl; };
	cout << totalChild() << endl;
	cout << typeid(totalChild).name() << endl;
	system("pause");
	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;

int main(void)
{
	int j = 12;
	auto by_val_lambda = [=] {
		return j + 1; 
	};
	auto by_ref_lambda = [&] {
		return j + 1; 
	};

	cout << "by_val_lambda: " << by_val_lambda() << endl;
	cout << "by_ref_lambda: " << by_ref_lambda() << endl;
	j++;
	cout << "by_val_lambda: " << by_val_lambda() << endl;
	cout << "by_ref_lambda: " << by_ref_lambda() << endl;
	system("pause");
	return 0;
}
#endif

#include <iostream>
using namespace std;

int main(void)
{
	int val = 0;
	/* 编译失败, 在 const 的 lambda 中修改变量 */
	//auto const_val_lambda = [=]() { val = 3; };
	auto const_mutable_lambda = [=]() mutable {val = 3; };
	cout << val << endl;
	auto const_ref_lambda = [&] { val = 3; };
	cout << val << endl;
	auto const_param_lambda = [&](int v) {v = 3; };
	cout << val << endl;
	system("pause");
	return 0;
}