#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<string> scores;
    //스코어 추출
    for (int i = 0; i != dartResult.size(); i++) {
        if (dartResult[i] >= '0' && dartResult[i] <= '9') {
            if (dartResult[i + 1] >= '0' && dartResult[i + 1] <= '9') {
                string s;
                s = dartResult[i];
                s += dartResult[i + 1];
                scores.push_back(s);
                i++;
            }
            else {
                scores.push_back("0");
                scores.back() = dartResult[i];
            }
        }
    }
    vector<string> options(3);
    int idx = 0;
    //옵션 추출
    for (int i = 0; i != 3; i++) {
        for (int j = idx; j != dartResult.size(); j++) {
            //옵션 만남
            if (dartResult[j] < '0' || dartResult[j] > '9') {
                options[i] += dartResult[j];
            }
            //스코어 만남
            else if (j > 1 && (dartResult[j] >= '0' && dartResult[j] <= '9')) {
                idx = j + 1;
                if (dartResult[j + 1] >= '0' && dartResult[j + 1] <= '9') {
                    idx++;
                }
                break;
            }
        }
    }

    vector<int> scores_int(3);
    //계산
    for (int i = 0; i != 3; i++) {
        for (const auto& elem : options[i]) {
            switch (elem)
            {
            case 'S':
                scores_int[i] = stoi(scores[i]);
                break;
            case 'D':
                scores_int[i] = stoi(scores[i]) * stoi(scores[i]);
                break;
            case 'T':
                scores_int[i] = stoi(scores[i]) * stoi(scores[i]) * stoi(scores[i]);
                break;
            case '*':
                scores_int[i] *= 2;
                if(i > 0) {
                    scores_int[i - 1] *= 2;
                }
                break;
            case '#':
                scores_int[i] *= -1;
                break;
            }
        }
    }
    answer = scores_int[0] + scores_int[1] + scores_int[2];
    return answer;
}