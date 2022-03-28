#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> dic;
map<string, vector<string>> reporter;

void splitInsert(string s, string& s1, string& s2) {
    for (int i = 0; i != s.size(); i++) {
        if (s[i] != ' ') {
            s1 += s[i];
        }
        else {
            break;
        }
    }
    for (int i = s1.size() + 1; i != s.size(); i++) {
        s2 += s[i];
    }
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    for (int i = 0; i != report.size(); i++) {
        string s1, s2;
        splitInsert(report[i], s1, s2);

        auto it = find(reporter[s1].begin(), reporter[s1].end(), s2);
        if (it == reporter[s1].end()) {
            reporter[s1].push_back(s2);
            dic[s2]++;
        }
    }

    vector<int> answer;
    for (int i = 0; i != id_list.size(); i++) {
        int num = 0;

        for (auto& elem : reporter[id_list[i]]) {
            if (dic[elem] >= k) {
                num++;
            }
        }
        answer.push_back(num);
    }

    return answer;
}