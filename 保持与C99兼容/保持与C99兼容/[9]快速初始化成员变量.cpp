#include <iostream>
using namespace std;
#if 0
class Init
{
public:
protected:
private:
	int a;
	const static int b = 0;// �������ǳ����ľ�̬�����������
	int c = 1;// ������������ ��������������
// 	static int d = 0;		//��̬��Ա��������ǹ����, �������ʼ��һ����ô�����������Խ����α��޸�
// 	static const double e = 1.3;//double ������
// 	static const char *const f = "e";//char ������
};

struct init  
{
	int a = 1;
	double b{ 1.3 };
};

int main(void)
{


	system("pause");
	return 0;
}
#endif
#if 0
struct C 
{
	C(int i) : c(i) {}
private:
	int c;
};

struct init 
{
	int a = 1;
	//string b("hello");
	//C c(1);
	string b{ "hello" };
	string c = "hello";
	C c{ 1 };
};
#endif

struct Mem 
{
	Mem()
	{
		cout << "Mem default, num: " << num << endl;
	}
	Mem(int i) : num(i)
	{
		cout << "Mem, num: " << num << endl;
	}

	int num = 2;
};

class Group
{
public:
	Group()
	{
		cout << "Group default. val" << val << endl;
	}
	Group(int i) : val('G'), a(i)
	{
		cout << "Group(int i). val = " << val << endl;
	}
	void NumOfA()
	{
		cout << "number A = " << a.num << endl;
	}
	void NumOfB()
	{
		cout << "number B = " << b.num << endl;
	}
protected:
private:
	char val{ 'g' };
	Mem a;
	Mem b{ 19 };
};

int main(void)
{
	Mem member;
	Group group;
	group.NumOfA();
	group.NumOfB();
	Group group2(7);

	group2.NumOfA();
	group2.NumOfB();

	system("pause");
	return 0;
}