#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> board;
int t, ans;

bool check(int row) {
    for (int i = 0; i != row; i++) {    // 행
        if (board[row] == board[i] ||   // 열
            row - i == abs(board[row] - board[i])) {     // 대각선
            return false;
        }
    }
    return true;
}

void bt(int row) {
    if (row == t) {
        ans++;
        return;
    }
    for (int col = 0; col != t; col++) {
        board[row] = col;
        if (check(row)) {
            bt(row + 1);
        }
    }
}

int solution(int n) {
    t = n;
    board.resize(n);
    bt(0);

    return ans;
}