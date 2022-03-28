#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	vector<int> array_sort;
	//array_sort에 선별하고 정렬할 배열 넣음. commands[i][0] - 1은 array의 ~번째 원소. 
	for (int i = 0; i != commands.size(); i++) {
		for (int j = commands[i][0] - 1; j <= commands[i][1] - 1; j++) {
			array_sort.push_back(array[j]);
		}
		sort(array_sort.begin(), array_sort.end());
		answer.push_back(array_sort[commands[i][2] - 1]);
		array_sort.clear();
	}
	return answer;
}