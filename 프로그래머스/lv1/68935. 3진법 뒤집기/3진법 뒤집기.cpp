#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	vector<int> triad;
	while(true) {
		if (n < 3) { 
			triad.push_back(n);
			break; 
		}
		triad.push_back(n % 3);
		n /= 3;
	}
	int multiple = 1;
	for (int i = triad.size() - 1; i >= 0; i--) {
		answer += triad[i] * multiple;
		multiple *= 3;
	}
	return answer;
}