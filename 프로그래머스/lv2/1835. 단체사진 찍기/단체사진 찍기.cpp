#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//간격 체크
bool interval_check(string& str, const char& c1, const char& c2, const char& sign, const char& diff_ch) {
    int diff = diff_ch - '0' + 1;
    int idx_c1 = str.find(c1);
    int idx_c2 = str.find(c2);
    if (sign == '=') {
        return (abs(idx_c1 - idx_c2) == diff);
    }
    else if (sign == '>') {
        return (abs(idx_c1 - idx_c2) > diff);
    }
    else if (sign == '<') {
        return (abs(idx_c1 - idx_c2) < diff);
    }

}

//순열
void permutation(const int& depth, string str, int& answer, vector<string>& data) {
    if (depth == 8) {
        bool check = true;
        for (const string& elem : data) {
            if (interval_check(str, elem[0], elem[2], elem[3], elem[4])) {
                check = true;
            }
            else {
                check = false;
                break;
            }
        }
        if (check) { answer++; }
        return;
    }
    for (int i = depth; i < 8; i++) {
        swap(str[depth], str[i]);
        permutation(depth + 1, str, answer, data);
        swap(str[depth], str[i]);
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string str = "ACFJMNRT";

    permutation(0, str, answer, data);
    
    return answer;
}