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
	/* default 就是使用默认构造函数 */
	/* 构造函数 = delete 就是不使用构造函数 */
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