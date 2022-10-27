#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    bool flag = false; // 등비
    if (common[2] - common[1] == common[1] - common[0]) flag = true;    // 등차
    
    if (flag)
    {
        return common.back() + common[1] - common[0];
    }
    else
    {
        return common.back() * common[1] / common[0];
    }
}