#include <iostream>
using namespace std;

/* typeid */

/*
	RTTI ���л���
	��ÿһ�����Ͳ���һ��type_info���͵�����
	����ʹ�� typeid ��ʱ���в鿴��ʲô������������ 
	type_info ��name�������Է�����������
	hash_code ���ظ�����Ψһ�Ĺ�ϣֵ
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