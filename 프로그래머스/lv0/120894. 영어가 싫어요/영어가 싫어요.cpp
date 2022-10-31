#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long solution(string numbers) {
    unordered_map<string, char> dic;
    dic["zero"] = '0';
    dic["one"] = '1';
    dic["two"] = '2';
    dic["three"] = '3';
    dic["four"] = '4';
    dic["five"] = '5';
    dic["six"] = '6';
    dic["seven"] = '7';
    dic["eight"] = '8';
    dic["nine"] = '9';
    
    string temp, ans;
    for (auto& ch : numbers)
    {
        temp += ch;
        if (temp.size() > 2 && dic[temp])
        {
            ans += dic[temp];
            temp = "";
        }
    }
    return stoll(ans);
}