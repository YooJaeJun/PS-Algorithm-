#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	//board의 수 의미: 인형 종류 //moves의 수 의미: 열 번째
	vector<int> basket;
	for (int i = 0; i != moves.size(); i++) {
		for (int j = 0; j != board.size(); j++) {
			if (board[j][moves[i] - 1] != 0) {	//열 n번째의 인형종류
				basket.push_back(board[j][moves[i] - 1]);
				board[j][moves[i] - 1] = 0;
				if (basket.size() > 1 && basket.back() == basket[basket.size() - 2]) {	//마지막 원소와 마지막 전 원소 비교
					answer = answer + 2;
					basket.pop_back();
					basket.pop_back();	//인형 2개씩
				}
				break;
			}
		}
	}
	return answer;
}