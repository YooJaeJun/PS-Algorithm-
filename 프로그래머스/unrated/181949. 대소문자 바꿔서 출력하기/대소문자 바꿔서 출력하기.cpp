#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for (auto& ch : str)
    {
        if (ch >= 'A' && ch <= 'Z')
            ch += ('a' - 'A');
        else
            ch -= ('a' - 'A');
    }
    
    cout << str;
    
    return 0;
}