#include <string>
#include <vector>

using namespace std;

int solution(vector<int> dot) {
    return (dot[0] > 0 && dot[1] > 0 ? 1 : dot[0] < 0 && dot[1] > 0 ? 2 : dot[0] > 0 && dot[1] < 0 ? 4 : 3);
}