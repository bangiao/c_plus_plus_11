#include <iostream>
using namespace std;

struct People 
{
public:
	int hand;
	static People *all;
};

int main(void)
{
	People p;

	cout << sizeof(p.hand) << endl;
	cout << sizeof(People::hand) << endl;//c++98中不存在, c++11中没有错
	cout << sizeof(People::all) << endl;
	system("pause");
	return 0;
}