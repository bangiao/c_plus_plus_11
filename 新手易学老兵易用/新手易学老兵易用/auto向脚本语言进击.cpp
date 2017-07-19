#if 0
#include <iostream>
using namespace std;
#endif
// auto ʵ�ֵı��ʾ��ǽ�����ƥ���ʱ���Ӻ������
/* auto ���ŵ� */
/*
	1. �˴���Ŀɶ��Ը���
	2. ���Ա���һЩ���������Ĵ���
	3. ����Ӧ��, һ���̶���֧�ַ��ͱ��
*/

#if 0
int main(void)
{
	auto str = "world\n";
	cout << str << endl;
	system("pause");
	return 0;
}
#endif

#if 0

auto foo()
{
	return 1.1;
}

int main(void)
{
	
	auto x = 1;
	auto y = foo();
	struct m 
	{
		int i = 0;
	}str;

	auto str1 = str;

// 	auto z;
// 	z = x;

	system("pause");
	return 0;
}

#endif 

// �����������ͱȽϸ��ӵ������
#if 0
#include <iostream>
#include <vector>
#include <string>

void loopver1(std::vector<std::string> &s)
{
	std::vector<std::string>::iterator it = s.begin();

	for (; it != s.end(); it++)
	{
		// .....
	}
}

void loopver2(std::vector<std::string> &s)
{
	auto it = s.begin();

	for (; it != s.end(); it++)
	{
		// .....
	}
}

int main(void)
{
	
	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

class PI
{
public:
	double operator*(float v)
	{
		return (((double)val) * v);
	}
	const float val = 3.141592653f;
};

int main(void)
{
	auto radius = 1.7e10;
	PI pi;
	auto circumference = 2 * (pi * radius);
	cout << circumference << endl;
	system("pause"); 
	return 0;
} 
#endif

// auto ���ܽ�����е������������
#if 0
#include <iostream>
using namespace std;

int main(void)
{
	unsigned int a = 4294967295;
	unsigned int b = 1;


	auto c = a + b; // ����� c ����unsigned int ����

	cout << "a = " << a << "  b = " << b << "  c = " << c << endl;
	
	system("pause");
	return 0;
}
#endif

// auto ���� auto = auto ���ͺ� auto a; ��Щ�ǲ��������
#if 0
#include <iostream>
using namespace std;

template <class T1, class T2>
double sum(T1 &t1, T2 &t2)
{
	auto s = t1 + t2;
	return s;
}

int main(void)
{
	int a = 3;
	long b = 5;
	float c = 1.0f, d = 2.3f;
	auto e = sum<int, long>(a, b);
	auto f = sum<float, float>(c, d);
	cout << e << endl << f << endl;
	system("pause");
	return 0;
}

#endif


//ʹ��auto��������ܵĺ궨��, ��ϧ����Ǵ��

// #include <iostream>
// using namespace std;
// 
// #define MAX(a, b) ((a) > (b)) ? (a) : (b)
// #define MAX2(a, b) ({ \ 
// auto __a = (a); \
// auto __b = (b); \
// (__a > __b) ? __a : __b})
// 
// int main(void)
// {
// 	int m1 = MAX(1, 2);
// 	int m2 = MAX2(3, 1);
// 	system("pause");
// 	return 0;
// }


// ������Ҫ���� & �����
#if 0
#include <iostream>
using namespace std;

int main(void)
{
	int x = 2;


	int *y = &x;
	auto * z = &x;
	auto a = &x;
	auto &b = x; // ������Ҫ���� & �����
	auto c = x;

	system("pause");
	return 0;
}
#endif

#if 0

//decltype �������Ƶ��������һ����

/* auto ������ */
//auto ������ʹ���ں����Ĳ�����
//���ǿ���ͨ�����ͱ��ʵ�� auto �������ƹ���
// auto ���Ե��������ķ���ֵ
//auto i = 0, j = 3.14f;// ����ʹ���
// ����������������ʽ��ʵ���ǿ��Ե�, ��Ϊ ���� ������ auto ���汻�жϳ� char ���� int ...
//��var��: �Ǿ�̬���ݳ�Ա���ܾ��а�����auto��������

//��auto[3]��: ���鲻�ܾ������а�����auto����Ԫ������
//"z": �����ʼ����Ҫ�����ŵĳ�ʼֵ�趨���б�
//auto z[3] = x;
//���� char z1[3] = x; ͬ��Ҳ�ǲ��е�


//ģ���������Ϊ������auto��������
//Clas<auto> cc;

#include <iostream>
using namespace std;

//auto ������ʹ���ں����Ĳ�����
//���ǿ���ͨ�����ͱ��ʵ�� auto �������ƹ���
// void func(auto i = 1)
// {
// 	cout << i << endl;
// }

// auto ���Ե��������ķ���ֵ
auto func2(int u)
{
	return u;
}


// struct str 
// {
// 	auto var = 10;   //��var��: �Ǿ�̬���ݳ�Ա���ܾ��а�����auto��������
// };

template <class T>
class Clas
{
public:
	Clas() {};
protected:
private:
};

int main(void)
{
	//auto i = 0, j = 3.14f;// ����ʹ���


	// ����������������ʽ��ʵ���ǿ��Ե�, ��Ϊ ���� ������ auto ���汻�жϳ� char ���� int ...
	auto i = new auto(1);
	auto y{ 1 };

	cout << "sizeof = " << sizeof(*i) << "  " << *i << endl;		// 4   1
	cout << "sizeof = " << sizeof(y) << "  " << y << endl;			// 4   1

	char x[3] = { 0 };
	//auto z[3] = x;
	//char z1[3] = x;

	Clas<int> c;
	//Clas<auto> cc;
	system("pause");
	return 0;
}

#endif

