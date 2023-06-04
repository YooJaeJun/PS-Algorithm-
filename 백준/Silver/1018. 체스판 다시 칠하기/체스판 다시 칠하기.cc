#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void color_print_impl(vector<vector<char>>& chess, const int& i, const int& j, int& ans) {
	if (chess[i][j] == 'W') {
		chess[i][j] = 'B';
	}
	else if (chess[i][j] == 'B') {
		chess[i][j] = 'W';
	}
	ans++;
}
void color_print(vector<vector<char>>& chess_copy, const int& a, const int& b, int& ans) {
	for (int i = a; i != a + 8; i++) {
		for (int j = b; j != b + 8; j++) {
			if (i > a && j == b && chess_copy[i][j] == chess_copy[i - 1][j]) {
				color_print_impl(chess_copy, i, j, ans);
			}
			if (j > b && chess_copy[i][j] == chess_copy[i][j - 1]) {
				color_print_impl(chess_copy, i, j, ans);
			}
		}
	}
}
int main() {
	int y, x;
	cin >> y >> x;

	//원본 색 세팅
	vector<vector<char>> chess(y, vector<char>(x));
	for (int i = 0; i != y; i++) {
		for (int j = 0; j != x; j++) {
			cin >> chess[i][j];
		}
	}

	vector<int> anss;
	for (int a = 0; a + 8 <= y; a++) {
		for (int b = 0; b + 8 <= x; b++) {

			vector<vector<char>> chess_copy;

			//최초값 그대로 가는 경우 == 오리진
			int ans_origin = 0;
			chess_copy = chess;
			color_print(chess_copy, a, b, ans_origin);

			anss.push_back(ans_origin);
			
			//최초값 반대색으로 바꾼 경우 == 리버스
			int ans_reverse = 1;
			chess_copy = chess;
			chess_copy[a][b] = (chess_copy[a][b] == 'W') ? 'B' : 'W';
			color_print(chess_copy, a, b, ans_reverse);

			anss.push_back(ans_reverse);
		}
	}
	cout << *min_element(anss.begin(), anss.end());

	return 0;
}