#include <iostream>
using namespace std;

int add(const int &a, const int &b)
{
	return a + b;
}

int main(void)
{
	/* �������ʽ */
	const int max_file = 27;	// T
	const int limit = max_file + 1;//T
	const int sz = add(1, 2);//F
	/* constexpr */
	constexpr int max_file2 = 27;
	constexpr int linit2 = max_file + 1;
	// error C2131: ���ʽ�ļ��������ǳ���
	// note: ��δ����ĺ�����Ϊδ����Ϊ��constexpr���ĺ����ĵ��õ����˹���
	// note: ��μ���add�����÷�
	//constexpr int sz2 = add(1, 2);

	/* ָ���constexpr */
	const int *p = nullptr;
	constexpr int *p2 = nullptr;// == int *const p2;
	int i = 10;
	const int *p3 = &i;
	constexpr int *p4 = &i;
	cout << *p4 << " " << p4 << endl;
	system("pause");
	return 0;
}