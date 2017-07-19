#if 0
#include <iostream>
#include <typeinfo>
using namespace std;
#endif
// decltype �ǻ�ȡĳ��������߱������ʽ( ... )������
#if 0
int main(void)
{
	int i;
	decltype(i) j = 0;
	cout << typeid(j).name() << endl;
	float a;
	double b;
	decltype(a + b) c;
	cout << typeid(c).name() << endl;
	system("pause");
	return 0;
}
#endif

#if 0
int main(void)
{
	using size_t = decltype(sizeof(0));
	using ptrdiff_t = decltype((int *)0 - (int *)0);
	using nullptr_t = decltype(nullptr);

	cout << typeid(size_t).name() << endl;
	cout << typeid(ptrdiff_t).name() << endl;
	cout << typeid(nullptr_t).name() << endl;
	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int > vec;
	using type_vector = decltype(vec);
	cout << typeid(type_vector).name() << endl;

	for (type_vector::iterator it = vec.begin(); it != vec.end(); it++)
	{
		// ��һЩ��
	}
	for (decltype(vec)::iterator it = vec.begin(); it != vec.end(); it++)
	{
		// ��һЩ��
	}
	system("pause");
	return 0;
}
#endif

// decltype ��������������͵�ʹ��
#if 0
#include <iostream>
using namespace std;

enum 
{
	K1,
	K2,
	K3
}anon_e;

union 
{
	decltype(anon_e) key;
	char *name;
}anon_u;

struct  
{
	int d;
	decltype(anon_u) id;
}anon_s;

int main(void)
{
	decltype(anon_s) as;
	as.id.key = decltype(anon_e)::K1;
	system("pause");
	return 0;
}
#endif

// decltype ���ڲ���

#if 0
#include <iostream>
using namespace std;

template <class T1, class T2>
void Sum(T1 &t1, T2 &t2, decltype(t1 + t2) &s)
{
	s = t1 + t2;
}

int main(void)
{
	int a = 3;
	long b = 5;
	float c = 1.0f, d = 2.3f;

	long e;
	float f;
	Sum(a, b, e);
	Sum(c, d, f);

	cout << typeid(e).name() << ": " << e << endl;
	cout << typeid(f).name() << ": " << f << endl;
	system("pause");
	return 0;
}
#endif

// �� result_of ��ȡ���������
#include <iostream>
#include <type_traits>
using namespace std;

typedef double(*func)();
//typedef unsigned char uchar;
template <class>
struct result_of;

// result_off ���ڲ�ʵ��
template <class F, class ... ArgTypes>
struct result_of<F(ArgTypes...)>
{
	using type = decltype(std::declval<F>()(std::declval<ArgTypes>()...));
};

int main(void)
{
	result_of<func()>::type f;
	cout << typeid(f).name() << endl;
	system("pause");
	return 0;
}