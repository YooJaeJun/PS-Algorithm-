#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string str = to_string(n);
	for (int i = 0; i != str.size(); i++) {
		for (int j = i + 1; j != str.size(); j++) {
			if (str[i] < str[j]) {
				char tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
		}
	}
	cout << str;
}