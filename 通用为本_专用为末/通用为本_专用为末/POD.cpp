#include <iostream>
using namespace std;
/*
ɶ��POD���ͣ�
PODȫ��Plain Old Data��ͨ�׵Ľ���һ�����ṹ��ͨ�������ƿ������ܱ��������ݲ��䣬��ô������һ��POD���͡�

ƽ���Ķ���
1.��ƽ���Ĺ��캯��
2.��ƽ���Ŀ������캯��
3.��ƽ�����ƶ����캯��
4.��ƽ���Ŀ�����ֵ�����
5.��ƽ�����ƶ���ֵ�����
6.��ƽ������������
7.���ܰ����麯��
8.���ܰ��������
*/



//ƽ���Ķ���
#if 0
class A { A() {} };
class B { B(B&) {} };
class C { C(C&&) {} };
class D { D operator=(D&) {} };
class E { E operator=(E&&) {} };
class F { ~F() {} };
class G { virtual void foo() = 0; };
class H : G {};
class I {};

int main(void)
{
	
	std::cout << std::is_trivial<A>::value << std::endl;  // �в�ƽ���Ĺ��캯��
	std::cout << std::is_trivial<B>::value << std::endl;  // �в�ƽ���Ŀ������캯��
	std::cout << std::is_trivial<C>::value << std::endl;  // �в�ƽ���Ŀ�����ֵ�����
	std::cout << std::is_trivial<D>::value << std::endl;  // �в�ƽ���Ŀ�����ֵ�����
	std::cout << std::is_trivial<E>::value << std::endl;  // �в�ƽ�����ƶ���ֵ�����
	std::cout << std::is_trivial<F>::value << std::endl;  // �в�ƽ������������
	std::cout << std::is_trivial<G>::value << std::endl;  // ���麯��
	std::cout << std::is_trivial<H>::value << std::endl;  // �������

	std::cout << std::is_trivial<I>::value << std::endl;  // ƽ������

	system("pause");
	return 0;
}

#endif


/*
��׼���ֵĶ���

1.���зǾ�̬��Ա����ͬ�ķ���Ȩ��
2.�̳��������ֻ����һ�����зǾ�̬���ݳ�Ա
3.����ĵ�һ���Ǿ�̬��Ա�������ǻ�������
4.û���麯��
5.û�������
6.���зǾ�̬��Ա�����ϱ�׼��������
*/

class A
{
private:
	int a;
public:
	int b;
};

class B1
{
	static int x1;
};

class B2
{
	int x2;
};

class B : B1, B2
{
	int x;
};

class C1 {};
class C : C1
{
	C1 c;
};

class D { virtual void foo() = 0; };
class E : D {};
class F { A x; };

int main(void)
{
	std::cout << std::is_standard_layout<A>::value << std::endl;  // Υ������1����Աa��b���в�ͬ�ķ���Ȩ��
	std::cout << std::is_standard_layout<B>::value << std::endl;  // Υ������2���̳���������(��)���ϵ����зǾ�̬��Ա
	std::cout << std::is_standard_layout<C>::value << std::endl;  // Υ������3����һ���Ǿ�̬��Ա�ǻ�������
	std::cout << std::is_standard_layout<D>::value << std::endl;  // Υ������4�����麯��
	std::cout << std::is_standard_layout<E>::value << std::endl;  // Υ������5���������
	std::cout << std::is_standard_layout<F>::value << std::endl;  // Υ������6���Ǿ�̬��Աx�����ϱ�׼��������

	system("pause");
	return 0;
}
