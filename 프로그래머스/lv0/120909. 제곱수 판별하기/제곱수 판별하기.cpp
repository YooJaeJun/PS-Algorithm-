#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int sq = sqrt(n);
    return sq * sq == n ? 1 : 2;
}