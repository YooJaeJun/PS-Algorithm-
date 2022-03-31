#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int n1, int n2) {
    string s1 = to_string(n1);
    string s2 = to_string(n2);
    return stoi(s1 + s2) > stoi(s2 + s1);
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), compare);
    string ans;
    int idx = 0;
    for (int i = 0; i != numbers.size(); i++) {
        if (idx == 0 && numbers[i] == 0) {
            continue;
        }
        idx = 1;
        ans += to_string(numbers[i]);
    }
    if (ans.empty()) return "0";
    return ans;
}