#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    sort(strings.begin(), strings.end(), [n](const auto& str1, const auto& str2) {
        if (str1[n] == str2[n]) return str1 <= str2;
        return str1[n] < str2[n]; 
        });
    return strings;
}