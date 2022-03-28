#include <string>
#include <vector>

using namespace std;

vector<bool> visited;

void dfs(vector<vector<int>>& computers, int x) {
    visited[x] = true;
    for (int i = 0; i != computers[x].size(); i++) {
        int elem = computers[x][i];
        if (visited[i] == false &&
            i != x && 
            elem != 0) {
            dfs(computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    visited.resize(n);
    for (int i = 0; i != n; i++) {
        if (visited[i] == false) {
            dfs(computers, i);
            answer++;
        }
    }
    return answer;
}