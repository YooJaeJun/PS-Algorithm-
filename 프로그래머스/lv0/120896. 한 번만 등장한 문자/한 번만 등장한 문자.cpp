#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer;
    map<char, int> dic;
    for (auto& ch : s)
    {
        if (dic[ch]) dic[ch] = -1;
        else dic[ch] = 1;
    }
    for (auto& elem : dic)
    {
        if (elem.second != -1 && elem.second != 0) answer += elem.first;
    }
    return answer;
}