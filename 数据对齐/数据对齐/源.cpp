#include <iostream>
using namespace std;

struct ColorVector 
{
	double a;
	double b;
	double c;
	double d;
	double e;
};

struct alignas(32) ColorVector2
{
	double a;
	double b;
	double c;
	double d;
	double e;
};

int main(void)
{

	// �鿴�ڴ���뷽ʽ
	cout << "alignof(ColorVector): " << alignof(ColorVector) << endl;
	cout << "alignof(ColorVector2): " << alignof(ColorVector2) << endl;
	system("pause");
	return 0;
}