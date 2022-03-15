#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int num = 0;
	int ret = 0;
	int seat = 1;
	for (int i = 0; !s.empty(); ++i) {
		if (s.back() >= 'A' && s.back() <= 'F') {
			num = s.back() - 'A' + 10;
		}
		else {
			num = s.back() - '0';
		}
		ret += num * seat;
		s.pop_back();
		seat *= 16;
	}
	printf("%d", ret);
	return 0;
}