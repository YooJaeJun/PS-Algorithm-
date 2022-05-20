#include <bits/stdc++.h>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while (1)
    {
        ++answer;
        if (abs(a - b) == 1 && abs(a / 2 - b / 2) == 1) 
            break;
        if (a % 2 == 1) a = a / 2 + 1;
        else a /= 2;
        if (b % 2 == 1) b = b / 2 + 1;
        else b /= 2;
        n /= 2;
    }

    return answer;
}