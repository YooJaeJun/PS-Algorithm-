#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(string my_string) {
    string answer;
    unordered_map<char, int> dic;
    for (auto& ch : my_string)
    {
        if (dic[ch]) continue;
        dic[ch] = 1;
        answer += ch;
    }
    return answer;
}