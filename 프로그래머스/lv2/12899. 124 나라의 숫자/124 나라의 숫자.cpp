#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(int n) {
    string answer;
    char tmp;
    int share, rest;
    share = n;
    while(true) {
        //3진법과 유사. 단, 0이 없어서 3으로 나누어 떨어지면 -1 처리
        if (share % 3 == 0) {
            rest = 3;
            share = share / 3 - 1;
        }
        else {
            rest = share % 3;
            share = share / 3;
        }
        if (rest == 3) { rest = 4; }
        answer.insert(answer.begin(), rest + '0');
        if (share < 3) {
            answer.insert(answer.begin(), share + '0');
            break;
        }
    }
    if (answer.front() == '0') {
        answer.erase(answer.begin());
    }
    return answer;
}