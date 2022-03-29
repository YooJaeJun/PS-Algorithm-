#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> operations) {
    map<int, int> dic;

    for (int i = 0; i != operations.size(); i++) {
        // 삽입
        if (operations[i][0] == 'I') {
            string key;
            for (int j = 2; j <= operations[i].size(); j++) {
                key += operations[i][j];
            }
            dic[stoi(key)]++;
        }
        // 삭제
        else {
            if (dic.empty()) { continue; }

            // 최대값
            if (operations[i][2] == '1') {
                auto it = dic.end();
                it--;
                if (it->second == 1) {
                    dic.erase(it);
                }
                else {  // 중첩 시 빼줌
                    it->second--;
                }
            }
            // 최소값
            else {
                auto it = dic.begin();
                if (it->second == 1) {
                    dic.erase(it);
                }
                else {
                    it->second--;
                }
            }
        }
    }

    vector<int> answer(2);
    if (dic.empty()) { answer = { 0, 0 }; }
    else {
        answer[0] = (--dic.end())->first;
        answer[1] = dic.begin()->first;
    }
    return answer;
}