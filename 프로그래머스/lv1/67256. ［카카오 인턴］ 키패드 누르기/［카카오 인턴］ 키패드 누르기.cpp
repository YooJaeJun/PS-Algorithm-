#include <string>
#include <vector>
using namespace std;

//모든 숫자들의 2, 5, 8, 0에 대한 거리
const int distance_arr[12][4] = { {1, 2, 3, 4}, {0, 1, 2, 3}, {1, 2, 3, 4},
	{2, 1, 2, 3}, {1, 0, 1, 2}, {2, 1, 2, 3},
	{3, 2, 1, 2}, {2, 1, 0, 1}, {3, 2, 1, 2},
	{4, 3, 2, 1}, {3, 2, 1, 0}, {4, 3, 2, 1},
};

const char get_distance(const int& elem, int& left, int& right, const string& hand) {
	char ret;
	int order = -1;	//디버그용
	switch (elem)
	{
	//distance_arr에서 2, 5, 8, 0 순
	case 2:	
		order = 0;
		break;
	case 5:	
		order = 1;
		break;
	case 8:	
		order = 2;
		break;
	case 11:	//11번째로 치환된 0
		order = 3;
		break;
	}
	if (distance_arr[left - 1][order] == distance_arr[right - 1][order]) {
		if (hand == "right") {
			right = elem;
			ret = 'R';
			return ret;
		}
		else if (hand == "left") {
			left = elem;
			ret = 'L';
			return ret;
		}
	}
	else if (distance_arr[left - 1][order] > distance_arr[right - 1][order]) {
		right = elem;
		ret = 'R';
		return ret;
	}
	else {
		left = elem;
		ret = 'L';
		return ret;
	}
}

string solution(vector<int> numbers, string hand) {
	string answer = "";

	//0과 *와 # 위치 정의
	const int pointer_sign = 10;
	const int zero_sign = 11;	//코드상 0을 11번째로 정의
	const int sharp_sign = 12;
	int left = pointer_sign;
	int right = sharp_sign;

	for (auto& elem : numbers) {
		switch (elem) {
		case 1:
		case 4:
		case 7:
			left = elem;
			answer += 'L';
			break;
		case 3:
		case 6:
		case 9:
			right = elem;
			answer += 'R';
			break;
		case 0:
			elem = 11;	//0은 11번째로 치환
		default:
			answer += get_distance(elem, left, right, hand);
			break;
		}
	}

	return answer;
}