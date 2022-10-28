#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    string s = to_string(num);
    int answer = s.find(k + '0');
    return answer == string::npos ? -1 : answer + 1;
}