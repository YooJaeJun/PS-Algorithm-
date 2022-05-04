#include <bits/stdc++.h>
using namespace std;
// #define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

long long gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long solution(int w, int h) {
    return (ll)w * h - ((ll)w + (ll)h - gcd(w, h));
}