#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for (char& elem : s) {
        if (elem != ' ') {
            if (elem >= 'a') {
                for (int i = 0; i != n; i++) {
                    if (++elem > 'z') {
                        elem = 'a';
                    }
                }
            }
            else if (elem <= 'Z') {
                for (int i = 0; i != n; i++) {
                    if (++elem > 'Z') {
                        elem = 'A';
                    }
                }
            }
        }
    }
    return s;
}