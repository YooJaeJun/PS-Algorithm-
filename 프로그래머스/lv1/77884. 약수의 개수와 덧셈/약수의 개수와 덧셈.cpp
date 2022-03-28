#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
	int answer = 0;
	int divisor_num = 0;
	for (int i = left; i <= right; i++) {
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) {
				divisor_num++;
			}
		}
		(divisor_num % 2 == 0) ? (answer += i) : (answer -= i);
		divisor_num = 0;
	}
	return answer;
}