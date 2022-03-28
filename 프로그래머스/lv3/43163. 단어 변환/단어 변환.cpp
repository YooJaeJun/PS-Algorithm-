#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 9999999;
vector<vector<bool>> nodes;
vector<bool> visited;
bool possible;
int answer;

bool isSimilar(string s1, string s2) {
    int sameNum = 0;
    for (int i = 0; i != s1.size(); i++) {
        if (s1[i] == s2[i]) {
            sameNum++;
        }
    }
    return sameNum >= s1.size() - 1;
}

void dfs(string begin, string target, vector<string>& words, int curIdx, int cnt) {
    if (begin == target) {
        answer = min(answer, cnt);
        visited[curIdx] = false;
        return;
    }

    for (int i = 0; i != words.size(); i++) {
        string word = words[i];
        if (visited[i] == false) {
            if (nodes[curIdx][i]) {
                visited[i] = true;
                dfs(word, target, words, i, cnt + 1);
            }
        }
    }

    visited[curIdx] = false;  // 회귀 시 방문 취소 처리
}

int solution(string begin, string target, vector<string> words) {
    answer = inf;
    // words에 target 검증
    possible = false;
    for (auto& word : words) {
        if (target == word) {
            possible = true;
            break;
        }
    }
    if (possible == false) { return 0; }
    // 동적할당
    nodes.resize(words.size() + 1); // +1은 begin 자리
    visited.resize(words.size() + 1);
    for (int i = 0; i != nodes.size(); i++) {
        nodes[i].resize(nodes.size() + 1);
    }

    // 글자 2개 이상 같으면 연결판단.
    for (int i = 0; i != words.size(); i++) {
        for (int j = 0; j != words.size(); j++) {
            if (i != j) {
                if (isSimilar(words[i], words[j])) {
                    possible = true;
                    nodes[i][j] = true; // 연결
                    nodes[j][i] = true; // 연결
                }
            }
        }
        // begin과 연결 판단
        if (isSimilar(begin, words[i])) {
            nodes[nodes.size() - 1][i] = true;
            nodes[i][nodes.size() - 1] = true;
        }
    }
    // 한 번도 연결된 적 없으면 리턴.
    if (possible == false) { return 0; }

    nodes[0][0] = true;
    dfs(begin, target, words, nodes.size() - 1, 0);

    return answer == inf ? 0 : answer;
}