#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> cores) {
    if (n <= cores.size()) return n;

    int remain = n - cores.size();  // 처음 size만큼 작업 들어감 고려
    int start = 1, end = *max_element(cores.begin(), cores.end()) * remain / cores.size(), mid;
    // (end 초기값 때문에 자꾸 틀림) 남은 작업을 최대값의 처리 시간을 가진 코어size개로 처리할 수 있는 시간
    int sum = 0;
    while (start <= end)
    {
        mid = (start + end) / 2;
        sum = 0;
        for (auto& core : cores)
        {
            sum += mid / core;
        }
        if (sum >= remain) end = mid - 1;
        else start = mid + 1;
    }

    int finalWork = start;
    // 전 작업 누적 일감 수 확인
    sum = 0;
    for (auto& core : cores)
    {
        sum += (finalWork - 1) / core;
    }
    // finalWork에서 누가 몇 번째인지
    for (int i=0; i<cores.size(); i++)
    {
        if (finalWork % cores[i] == 0) sum++;
        if (sum == remain) 
            return i + 1;
    }
}