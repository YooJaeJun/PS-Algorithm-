#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int courseCnt = 0;
vector<string> answer;
vector<bool> checked;
int courseCntMax = 0;

// 조합 백트래킹
void bt(vector<string>& orders, string order, string s, int depth, int courseNum, int idx) {
    // 뽑힌 문자가 course[i]와 같으면 검사
    if (depth == courseNum) {
        // 이미 정답에 있으면 검사x
        for (auto& elem : answer) {
            if (order == elem) {
                return;
            }
        }
        // orders 각 요소에 v 문자 하나하나 포함되어 있는지 검사
        bool hasV = true;
        for (int i = 0; i != orders.size(); i++) {
            for (int j = 0; j != s.size(); j++) {
                if (orders[i].find(s[j]) != string::npos) {
                    hasV = true;
                }
                else {
                    hasV = false;
                    break;
                }
            }
            if (hasV) {
                courseCnt++;
            }
        }

        // 2개 이상 코스에 포함되면, 포함된 횟수가 최대인지 검사.
        if (courseCnt >= 2) {
            if (courseCntMax == courseCnt) {
                answer.push_back(s);
            }
            else if (courseCntMax < courseCnt) {
                for (int i = 0; i != answer.size(); ) {
                    if (s.size() == answer[i].size()) {
                        answer.erase(answer.begin() + i);
                    }
                    else {
                        i++;
                    }
                }
                answer.push_back(s);
                courseCntMax = courseCnt;
            }
        }
        courseCnt = 0;
        return;
    }

    // 문자열의 n개 문자만큼 뽑기 반복
    for (int i = idx; i != order.size(); i++) {
        if (checked[i] == false) {
            checked[i] = true;
            string str = s + order[i];
            sort(str.begin(), str.end());
            bt(orders, order, str, depth + 1, courseNum, i);
            checked[i] = false;
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    for (int i = 0; i != course.size(); i++) {
        courseCntMax = 0;
        for (auto& order : orders) {
            checked.resize(order.size());
            fill(checked.begin(), checked.end(), false);
            bt(orders, order, {}, 0, course[i], 0);
        }
    }

    // 정렬 및 중복 제거
    sort(answer.begin(), answer.end());
    for (auto& elem : answer) {
        sort(elem.begin(), elem.end());
    }
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}