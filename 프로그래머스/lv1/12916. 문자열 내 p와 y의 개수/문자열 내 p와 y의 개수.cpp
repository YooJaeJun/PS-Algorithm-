#include <string>
#include <iostream>
using namespace std;

bool solution(string s) {
    int num = 0;
    for (const char& elem : s) {
        if (elem == 'p' || elem == 'P') {
            num++;
        }
        else if (elem == 'y' || elem == 'Y') {
            num--;
        }
    }
    return num == 0 ? true : false;
}