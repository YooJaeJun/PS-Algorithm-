#include <string>
#include <vector>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    map<string, int> dic;
    for (auto& elem : phone_book) {
        dic[elem]++;
    }
    for (auto it = dic.begin(); it != --dic.end(); ) {
        string s1 = it++->first;
        string s2 = it->first;
        int minSize = min(s1.size(), s2.size());
        bool isSame = true;
        for (int i = 0; i != minSize; i++) {
            if (s1[i] != s2[i]) {
                isSame = false;
                break;
            }
        }
        if (isSame) { return false; }
    }
    return true;
}