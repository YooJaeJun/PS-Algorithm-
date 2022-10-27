#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    int a = (total * 2 / num - num + 1) / 2;
    vector<int> ans;
    for (int i=0; i<num; i++)
    {
        ans.push_back(a + i);
    }
    return ans;
}