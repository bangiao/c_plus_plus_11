#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

vector<int > vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

int main(void)
{
	std::function<int(int)> square = [](int i)->int { return i * i; };
	cout << square(5) << endl;
	system("pause");
	return 0;
}