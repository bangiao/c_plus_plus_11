#include <iostream>
using namespace std;

class Test
{
public:
	Test(int a = 0)
	{
		this->a = a;
	}
private:
	int a;
};

class String
{
public:
	/* default ����ʹ��Ĭ�Ϲ��캯�� */
	/* ���캯�� = delete ���ǲ�ʹ�ù��캯�� */
// 	String() = delete;
// 	String(const String &) = delete;
// 	String&operator=(const String &) = delete;

	String()
	{
		memset(this->buf, 0, sizeof(this->buf));
	}
	String(const String &s, int nLen) : String()
	{
		memcpy(this->buf, 0, sizeof(this->buf));
	}
protected:
private:
	char buf[_MAX_PATH]{ 0 };
	Test t;
};

int main(void)
{

	system("pause");
	return 0;
}