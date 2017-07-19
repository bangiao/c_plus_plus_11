#include <memory>
#include <iostream>
using namespace std;

int main(void)
{
	// 这个unique_ptr 的用法就类似于单例
	unique_ptr<int> up1(new int(11));
	//unique_ptr<int> up2 = up1;	//不能通过编译
	cout << *up1 << endl;
	unique_ptr<int> up3 = move(up1);	// up3 现在是数据的唯一的 unique_ptr智能指针
	cout << *up3 << endl;
	//cout << *up1 << endl;
	up3.reset();//释放
	up1.reset();//释放
	//cout << *up3 << endl; //释放掉
	// shared_ptr 就是用法和普通的指针差不多
	shared_ptr<int> sp1(new int(22));
	shared_ptr<int> sp2 = sp1;
	cout << *sp1 << endl;
	cout << *sp2 << endl;
	sp1.reset();
	cout << *sp2 << endl;
	system("pause");
	return 0;
}