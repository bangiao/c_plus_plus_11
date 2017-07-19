#include <iostream>
#include <string>
using namespace std;

class Pointer
{
public:
	Pointer(const int i, const string &n)
	{
		mptr = new int[i];
		length = i;
		name = n;
		cout << "���������캯��\n";
		showID();
	}
	Pointer() : mptr(nullptr), length(0) 
	{ 
		cout << "�޲������캯��\n"; showID(); 
	}
	
	virtual ~Pointer()
	{
		cout << name + "��������\n";
		if (mptr)
			delete[] mptr;
		mptr = nullptr;
	}

	Pointer(const Pointer& s)
	{
		length = s.getlen();
		mptr = new int[length];
		name = s.name;
		cout << "���ƹ��캯��\n";
		showID();
	}
	Pointer& operator=(const Pointer &s)
	{
		if (this == &s)
			return *this;
		if (mptr)
			delete[] mptr;
		length = s.getlen();
		mptr = new int[length];
		name = s.name;
		cout << "��ֵ�����\n";
		showID();
		return *this;
	}

	//�ƶ����캯��������s������const Pointer&& s����ΪҪ�ı�s�ĳ�Ա���ݵ�ֵ
	Pointer(Pointer&& s)
	{
		length = s.getlen();
		mptr = s.getmptr();
		name = s.name + "_yidonggouzao";//�����ƶ����캯��ʱ����һ�����
		s.mptr = nullptr;
		cout << "�ƶ����캯��\n";
		showID();
	}

	//�ƶ���ֵ�����
	Pointer& operator=(Pointer&& s)
	{
		cout << typeid(s).name() << endl;
		if (this == &s)
			return *this;
		if (mptr)
			delete[] mptr;
		length = s.getlen();
		mptr = s.mptr;
		name = s.name + "_yidongfuzhi";//�����ƶ���ֵ�����ʱ����һ�����
		s.mptr = nullptr;
		cout << "�ƶ���ֵ�����\n";
		showID();
		return *this;
	}

	void showID()
	{
		cout << "���ȣ�" << length << "  ָ�룺" << mptr << "  ���֣�" << name << endl;
	}

	int getlen() const
	{
		return length;
	}

	int* getmptr()const
	{
		return mptr;
	}

private:
	int* mptr;
	int length;
	string name = "#NULL";//�ò���������ǲ�ͬ�Ķ���c++11֧��ֱ����������ݳ�Ա���崦��ʼ��
};

Pointer test()
{
	Pointer a(2, "test");
	return a;
}

int main(void)
{
	//�ӻ�������Ϊ�˹۲����������ĵ���
	{
		Pointer(4, "notname1");

		Pointer a1 = test();//�����ƶ����캯������������a1
		cout << "a1.showID():\n";
		a1.showID();

		Pointer a2;
		a2 = Pointer(5, "notname2");//�����ƶ���ֵ�����

		Pointer a3(Pointer(7, "notname3"));//�˴�û�е����ƶ����캯����Ҳ����˵Pointer(7, "notname3") �������û�б��������٣���������ʱ��������Ҳ������Ϊ����������a3�����Բ�����ʱ������

		cout << "a3.showID():\n";
		a3.showID();//��֤a3ȷʵ��Pointer(7, "notname3")
	}

	cout << endl;
	system("pause");
	return 0;
}