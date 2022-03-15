#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

const string str_cut(int n) {
	string s = to_string(n);
	string s_cut;
	s_cut += s[s.size() - 2];
	s_cut += s[s.size() - 1];
	return s_cut;
}
int main() {
	int n, f;
	cin >> n >> f;
	n -= stoi(str_cut(n));
	for (int i = 0;; ++i) {
		if (n % f == 0) {
			cout << str_cut(n);
			break;
		}
		else {
			n++;
		}
	}
	return 0;
}