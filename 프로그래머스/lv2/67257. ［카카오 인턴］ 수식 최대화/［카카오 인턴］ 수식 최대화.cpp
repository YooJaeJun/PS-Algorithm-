#include <string>
#include <vector>
#include <cmath>

using namespace std;

string oper, operCopy;
string operKind = "*+-";
vector<long long> nums, numsCopy;
long long ans = 0;
vector<bool> visited;

void comb(string operStr) {
    if (operStr.size() == 3) {
        long long ret = 0;

        for (int i = 0; i != 3; i++) {
            int operIdx = -1;
            do {
                operIdx = oper.find(operStr[i]);
                if (operIdx == string::npos) continue;

                if (operStr[i] == '*') {
                    ret += nums[operIdx] * nums[operIdx + 1];
                }
                else if (operStr[i] == '+') {
                    ret += nums[operIdx] + nums[operIdx + 1];
                }
                else {
                    ret += nums[operIdx] - nums[operIdx + 1];
                }
                oper.erase(oper.begin() + operIdx);
                nums[operIdx] = ret;
                nums.erase(nums.begin() + operIdx + 1);
                ret = 0;

            } while (operIdx != string::npos);

        }

        ans = max(ans, abs(nums[0]));

        // 초기화
        ret = 0;
        oper = operCopy;
        nums.resize(numsCopy.size());
        for (int i = 0; i != nums.size(); i++) {
            nums[i] = numsCopy[i];
        }

        return;
    }

    for (int i = 0; i < 3; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        comb(operStr + operKind[i]);
        visited[i] = false;
    }
}


void split(string s) {
    string st;
    for (int i = 0; i != s.size(); i++) {
        if (s[i] == '*' || s[i] == '+' || s[i] == '-') {
            nums.push_back(stoi(st));
            oper += s[i];
            st = "";
        }
        else {
            st += s[i];
        }
    }
    nums.push_back(stoi(st));
}

long long solution(string expression) {
    split(expression);

    visited.resize(3);
    operCopy = oper;
    numsCopy.resize(nums.size());
    for (int i = 0; i != nums.size(); i++) {
        numsCopy[i] = nums[i];
    }
    
    comb("");
    return ans;
}

int main() {
    solution("100-200*300-500+20");
    return 0;
}