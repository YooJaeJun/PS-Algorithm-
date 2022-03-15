#include <iostream>
#include <map>
using namespace std;

int main() {
	multimap<int, string> members;
	int n;
	cin >> n;
	while (n--) {
		int age;
		string name;
		cin >> age >> name;
		members.insert({ age, name });
	}
	for (auto it = members.begin(); it != members.end(); it++) {
		cout << it->first << " " << it->second << "\n";
	}

	return 0;
}