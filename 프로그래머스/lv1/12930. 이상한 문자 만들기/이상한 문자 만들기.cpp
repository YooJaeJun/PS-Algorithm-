#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    for (int i = 0, idx = 0; i != s.size(); i++) {
        if (s[i] == ' ') {
            idx = 0;
        }
        else {
            if (idx % 2 == 0) {
                s[i] = toupper(s[i]);
            }
            else {
                s[i] = tolower(s[i]);
            }
            idx++;
        }
    }
    return s;
}