#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for (auto& ch : str)
        cout << ch << '\n';
    return 0;
}