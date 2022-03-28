#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    for (int i = 0, idx = 0; i != s.size(); i++) {
        if (s[i] == ' ') {
            idx = 0;
        }
        else {
            if (idx == 0 && s[i] >= 'a' && s[i] <= 'z') {
                s[i] = toupper(s[i]);
            }
            else if (idx != 0 && s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = tolower(s[i]);
            }
            idx++;
        }
    }
    return s;
}