#include <bits/stdc++.h>
using namespace std;

int ans = 0;

// 소수 판정
bool checkPrime(long long n)
{
    if(n <= 1) return false;
    int i = 2;
    while((long long)i * i <= n)
    {
        if(n % i == 0)
        {
            return false;
        }
        i++;
    }
    return true;
}

// 끊어서 검사
void checkSplit(string s)
{
    string splited;
    for(int i=0; i<s.size(); ++i)
    {
        if(s[i] == '0' && splited != "")
        {
            if(checkPrime(stoll(splited)))
                ans++;
            splited = "";
        }
        else
            splited += s[i];
    }
    if(splited != "")
    {
        if (checkPrime(stoll(splited))) ans++;
    }
}

// k진수로 변경
string convertK(int n, int k)
{
    int origin = n;
    string s;
    for(int i=0; n >= k; ++i)
    {
        s = to_string(n % k) + s;
        n /= k;
    }
    s = to_string(n) + s;
    
    return s;
}

int solution(int n, int k) {
    checkSplit(convertK(n, k));
    return ans;
}