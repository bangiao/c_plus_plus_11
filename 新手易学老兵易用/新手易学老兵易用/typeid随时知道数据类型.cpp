#include <iostream>
using namespace std;

/* typeid */

/*
	RTTI 运行机制
	对每一个类型产生一个type_info类型的数据
	可以使用 typeid 随时进行查看是什么样的数据类型 
	type_info 的name函数可以返回类型名字
	hash_code 返回该类型唯一的哈希值
*/

class White
{
public:
protected:
private:
};

class Black
{
public:
protected:
private:
};

int main(void)
{
	White w;
	Black b;

	cout << typeid(w).name() << endl;
	cout << typeid(b).name() << endl;
	
	White c;

	bool w_b_sametype = (typeid(w).hash_code() == typeid(b).hash_code());
	bool w_c_sametype = (typeid(w).hash_code() == typeid(c).hash_code());

	cout << w_b_sametype << endl << w_c_sametype << endl;
	system("pause");
	return 0;
}