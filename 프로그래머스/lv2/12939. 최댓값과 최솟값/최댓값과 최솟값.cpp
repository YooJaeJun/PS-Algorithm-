#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int min = 0, max = 0;
    string s2;
    bool is_first = true;
    for (int i = 0; i != s.size(); i++) {
        if (s[i] != ' ') {
            s2 += s[i];
        }
        else if (s[i] == ' ') {
            if (is_first) {
                min = stoi(s2);
                max = min;
            }
            is_first = false;

            min = min < stoi(s2) ? min : stoi(s2);
            max = max > stoi(s2) ? max : stoi(s2);
            s2 = "";
        }
    }
    //마지막
    min = min < stoi(s2) ? min : stoi(s2);
    max = max > stoi(s2) ? max : stoi(s2);
    

    return to_string(min) + ' ' + to_string(max);
}