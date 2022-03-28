#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string s = to_string(n);
    int size = s.size();
    for (int i = 0; i != size; i++) {
        answer.push_back(s.back() - '0');
        s.pop_back();
    }
    return answer;
}