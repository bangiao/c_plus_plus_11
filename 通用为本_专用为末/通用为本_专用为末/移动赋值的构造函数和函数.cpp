#include <iostream>
using namespace std;

// �ƶ���ֵ��ҪĿ����Ϊ�˽���ʱ������߱������������ڱ�ø���
// �������ʱ�����ĵ�ַ(�ڴ�)��������ʹ��
// �������ʹ�õ���һ���Ѿ����ڵĶ���ȥ�ƶ���ֵ�Ļ�, ����ǲ��������

// ���仰˵, ������ʱ�Ķ��Ǳ�����ʹ�õ�

class A
{
public:
	A(int a = 0)
	{
		this->a = a;
	}
	void operator=(A &&others)
	{
		this->a = others.a;
	}
	A(const A &&Ohter)  //�ƶ����캯��
	{
		this->a = Ohter.a;
	}
	void visit()
	{
		cout << this->a << endl;
	}
private:
	int a;
};



int main(void)
{
	A a;
	A b(A(2));
	//A c(b);		// ��A::A(const A &)��: ����������ɾ���ĺ���    ���������ڴ˴����ɡ�A::A��

	a.visit();
	b.visit();
	b = A(5);
	b.visit();
	system("pause");
	return 0;
}