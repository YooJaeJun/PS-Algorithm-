#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	char c[101];
	while (scanf("%[^\n]s", c) != EOF) {	//%[^\n]s 있어야 공백을 출력할 때 엔터로 안 띄움
		printf("%s\n", c);
		getchar();
		//while (getchar() != '\n') {}
	}
	return 0;
}