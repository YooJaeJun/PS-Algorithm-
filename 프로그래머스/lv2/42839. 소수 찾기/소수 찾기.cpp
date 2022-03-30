#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<bool> isPrime;

void checkPrime(int n) {
    isPrime[0] = false;
    isPrime[1] = false;
    int nSq = sqrt(n);
    for (int i = 0; i <= nSq; i++) {
        if (isPrime[i] == false) continue;
        for (int j = 2; i * j <= n; j++) {
            isPrime[i * j] = false;
        }
    }
}

string numbers_;
vector<int> strNums;
vector<bool> check;

void dfs(string strVia, int size) {
    if (strVia.size() == size) {
        strNums.push_back(stoi(strVia));
        return;
    }

    for (int i = 0; i != numbers_.size(); i++) {
        if (check[i] == false) {
            check[i] = true;
            dfs(strVia + numbers_[i], size);
            check[i] = false;
        }
    }
}

int solution(string numbers) {
    numbers_ = numbers;
    check.resize(numbers_.size());
    for (int i = 1; i <= numbers_.size(); i++) {
        fill(check.begin(), check.end(), false);
        dfs("", i);
    }

    sort(strNums.begin(), strNums.end());
    strNums.erase(unique(strNums.begin(), strNums.end()), strNums.end());
    int maxNum = *max_element(strNums.begin(), strNums.end());
    isPrime.resize(maxNum + 1, true);
    checkPrime(maxNum);

    int answer = 0;
    for (auto& elem : strNums) {
        if (isPrime[elem]) {
            answer++;
        }
    }
    return answer;
}