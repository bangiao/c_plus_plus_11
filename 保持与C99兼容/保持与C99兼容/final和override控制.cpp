#include <iostream>
using namespace std;

//1. final �ؼ��ֵĹ��ܾ��ǽ���ǵ�������麯���޷�����д

//(1) ��D1��: �޷��ӡ�B1���̳У���Ϊ���ѱ�����Ϊ��final��
// class B1 final
// {
// };
// class D1 : B1
// {
// };


//(2) ��B2::f��: ����Ϊ��final���ĺ����޷�����D2::f����д
// struct B2 
// {
// 	virtual void f() final = 0;
// };
// 
// struct D2 : B2 
// {
// 	void f() {}
// };

/*
	2. ���� D3 �ĳ���Ա�������дB3::f�����𣿻���˵��
		��ֻ�ǲ�С��д�˸��븸��ͬ���ĺ�����
		ȴ�ڲ�����䵼���˸��ǣ�Ϊ�˱������ִ���
		C++ 11 ������override�ؼ��֣���ô�� C# ������
 */

struct B4 
{
	virtual void g(int) {}
};

struct D4 : B4 
{
	void g(int) override {}
	//void g(double) override {}  // ��Ȼ��Ҫ���� override �Ĳ���, ����ʵ���ϸ��ಢû���������
};

int main(void)
{
	B4 b;
	b.g(12);

	system("pause");
	return 0;
}
