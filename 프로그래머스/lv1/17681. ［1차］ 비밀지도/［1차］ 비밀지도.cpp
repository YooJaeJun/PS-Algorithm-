#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    for (int i = 0; i != n; i++) {
        int a = arr1[i] | arr2[i];
        for (int j = 0; j != n; j++) {
            if (a % 2 == 0) {
                answer[i] = ' ' + answer[i];
            }
            else {
                answer[i] = '#' + answer[i];
            }
            a /= 2;
            if (a == 1) {
                answer[i] = '#' + answer[i];
                if (answer[i].size() < n) {
                    while (answer[i].size() != n) {
                        answer[i] = ' ' + answer[i];
                    }
                }
                break;
            }
        }
    }
    return answer;
}