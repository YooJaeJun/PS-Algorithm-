#include <string>
#include <vector>

using namespace std;

string decimalToBin(long long num) {
    string ret;
    while (num > 0) {
        ret = num % 2 == 0 ? '0' + ret : '1' + ret;
        num /= 2;
    }
    return ret;
}

int findZeroIdx(string s) {
    int ret = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '0') {
            return ret;
        }
        ret++;
    }
    return s.size();
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> ans;
    for (auto& num : numbers) {
        string s1 = decimalToBin(num);
        // 뒤부터 최초 0이 나오는 곳 찾기
        // 1010100011 == 1011 경우 == 11 경우와 같음
        int idx = findZeroIdx(s1);
        // 규칙: 01 2^0번, 011 2^1번, 0111 2^2번
        long long coef = 1;
        for (int i = 2; i <= idx; i++) {
            coef *= 2;
        }
        ans.push_back(num + coef);
    }
    return ans;
}