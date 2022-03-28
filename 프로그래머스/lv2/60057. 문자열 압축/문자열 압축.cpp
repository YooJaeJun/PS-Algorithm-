#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const vector<string> split_vec(string s, const int& cut) {
    vector<string> v;
    int coef = 0;
    int size = s.size();
    if (size % cut != 0) {
        coef = 1;
    }
    for (int i = 0; i != size / cut + coef; i++) {
        v.push_back(s.substr(0, cut));
        s.erase(0, cut);
    }
    return v;
}
int solution(string s) {
    int answer = 0;
    vector<string> v;
    vector<int> nums;
    int same_previous = 0;
    int idx = 0;
    if (s.size() == 1) {
        return 1;
    }
    for (int cut = 1; cut <= s.size() / 2; cut++) {   //cut == 자를 문자수
        v = split_vec(s, cut); //스트링 벡터에 split한 스트링들을 요소로 담음
        nums.push_back(cut);
        for (int elem = 0;; elem++) {
            if (elem == v.size() - 1) {
                break;
            }
            if (v[elem] == v[elem + 1]) {
                if (!same_previous) {
                    nums[idx]++;
                }
                //다음 문자열이 같은데, 전전과 전이 같았으면 (ex. 2ab -> 3ab) 문자열 수의 증감은 없다.
                same_previous++;
                //ex. 9a -> 10a : 문자열 증감 +1
                if (same_previous == 9 || same_previous == 99) {
                    nums[idx]++;
                }
            }
            else {
                if (v[elem].size() == v[elem + 1].size()) {
                    nums[idx] += cut;
                }
                //마지막 문자열이 정확히 떨어지지 않을 경우.
                else {
                    nums[idx] += v[elem + 1].size();
                }
                same_previous = 0;
            }
        }
        same_previous = 0;
        idx++;
    }
    answer = *min_element(nums.begin(), nums.end());
    return answer;
}