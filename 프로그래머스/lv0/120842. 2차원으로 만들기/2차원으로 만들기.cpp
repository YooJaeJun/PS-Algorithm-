#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer(1);
    for (int i=0; i<num_list.size(); i++)
    {
        answer.back().push_back(num_list[i]);
        if (i != 0 && i % n == n - 1) answer.resize(answer.size() + 1);
    }
    answer.pop_back();
    return answer;
}