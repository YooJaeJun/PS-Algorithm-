#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer;
    for (auto& elem : numlist)
    {
        if (elem % n == 0) answer.push_back(elem);
    }
    return answer;
}