#include <iostream>
#include <string>
using namespace std;

int rev(const int num) {
	string str = to_string(num);
	string rev;
	for (int i = str.size() - 1; i >= 0; i--) {
		rev.push_back(str[i]);
	}
	return stoi(rev);
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << rev(rev(a) + rev(b));
}