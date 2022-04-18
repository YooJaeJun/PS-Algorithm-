#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void bigToSmall(string& s) {
    for (int i = 0; i != s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += ('a' - 'A');
        }
    }
}

bool isAlphabet(char c) {
    return c >= 'a' && c <= 'z';
}

vector<string> split(string& s) {
    vector<string> ret;
    for (int i = 0; i != s.size() - 1; i++) {
        if (isAlphabet(s[i]) && isAlphabet(s[i + 1])) {
            string tmp;
            tmp += s[i];
            tmp += s[i + 1];
            ret.push_back(tmp);
        }
    }
    return ret;
}

vector<string> findCommon(vector<string> s1, vector<string> s2) {
    vector<string> ret;
    for (auto& elem1 : s1) {
        for (auto& elem2 : s2) {
            if (elem1 == elem2) {
                ret.push_back(elem1);
                elem2 = "";
                break;
            }
        }
    }
    return ret;
}

vector<string> findSum(vector<string> s1, vector<string> s2) {
    vector<string> ret;
    for (auto& elem1 : s1) {
        for (auto& elem2 : s2) {
            if (elem1 == elem2) {
                elem2 = "";
                break;
            }
        }
        ret.push_back(elem1);
    }
    for (auto& elem2 : s2) {
        if (elem2 != "") {
            ret.push_back(elem2);
        }
    }

    return ret;
}

int solution(string str1, string str2) {
    double j;
    const int coef = 65536;

    bigToSmall(str1);
    bigToSmall(str2);
    vector<string> vs1 = split(str1);
    vector<string> vs2 = split(str2);

    vector<string> common = findCommon(vs1, vs2);
    vector<string> sum = findSum(vs1, vs2);

    if (common.size() == 0 && sum.size() == 0) {
        return coef;
    }
    else {
        j = (double)common.size() / sum.size();
    }

    int answer = j * coef;
    return answer;
}