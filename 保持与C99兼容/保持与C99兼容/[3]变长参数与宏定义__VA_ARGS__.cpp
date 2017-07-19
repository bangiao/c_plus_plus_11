#include <stdio.h>
#include <stdlib.h>

// __VA_ARGS__ 可以在宏定义的时候替换 ... 

#define PR(...) printf(__VA_ARGS__);

#define LOG(...) { \
	fprintf(stderr, "%s: Line %d: \t", __FILE__, __LINE__);\
	fprintf(stderr, __VA_ARGS__);\
	fprintf(stderr, "\n");\
}

// int main()
// {
// 	int x = 3;
// 	LOG("x = %d", x);
// 	PR("x = %d\n", x);
// 	system("pause");
// 	return 0;
// }