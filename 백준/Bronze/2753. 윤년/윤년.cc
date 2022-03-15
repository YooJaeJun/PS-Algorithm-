#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	bool isleapyear = false;
	int year;
	scanf("%d", &year);
	if (year % 4 == 0 && (!(year % 100 == 0) || year % 400 == 0)) {
		isleapyear = true;
	}
	printf("%d", isleapyear);
	return 0;
}