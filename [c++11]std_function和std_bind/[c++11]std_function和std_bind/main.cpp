#include <iostream>
#include <functional> 
using namespace std;

// һ�����ܰ���thisָ��ĺ���һ������
// std::function<�����Ĳ����б�> ��������;ͺͺ���ָ���Ч��һ��, �������ķ�Χ�� ȫ�ֺ�������ľ�̬��Ա������
// std::bind Ҳ�Ǻ� ����ָ������һ��, ���������԰� ��ĳ�Ա����
// std::function<void (int)>  void �Ƿ���ֵ, int �ǲ���
// fp2 f = std::bind(&m_func3, this, std::placeholders::_1); ��һ���Ǻ���ָ��, 
//	�ڶ����Ǻ������� this �������� ����ռλ��, ��ʾ����һ������

typedef std::function<void()> fp;

void g_func()
{
	cout << "my name is g_func()" << endl;
}

class A
{
public:
	static void m_func1()
	{
		cout << "my name is static m_func1()" << endl;
	}

	void m_func2()
	{
		cout << "my name is m_func2()" << endl;
	}

	void m_func3(int a)
	{
		cout << "my name is m_func3 the value is " << a << endl;
	}

	virtual void m_virtual_fun()
	{
		cout << "this is parent func m_virtual_fun " << endl;
	}

	void init1()
	{
		fp fp1 = std::bind(&A::m_func2, this);
		fp1();
	}

	void init2()
	{
		typedef std::function<void(int)> fp2;
		fp2 f = std::bind(&A::m_func3, this, std::placeholders::_1);
	}

	void init3_virtual()
	{
		typedef std::function<void()> fp3;
		fp3 f3 = std::bind(&A::m_virtual_fun, this);
	}
};

class B : public A
{
public:
	using A::m_func1;
	using A::m_func2;
	using A::m_func3;
	using A::init1;
	using A::init2;
	virtual void m_virtual_fun()
	{
		cout << "child func m_virtual_func" << endl;
	}
protected:
private:
};

int main(void)
{
	A *a = new B;

	a->init1();
	a->init2();
	a->m_virtual_fun();		// ������̬

	delete a;
	a = nullptr;

	// ����ȫ�ֺ���, �;�̬������
	fp p = fp(&A::m_func1);
	p();

	fp p2 = fp(&g_func);
	p2();

	system("pause");
	return 0;
}