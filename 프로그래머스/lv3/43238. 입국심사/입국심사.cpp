#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solution(int n, vector<int> times) {
    function<ll()> bound = [&]() ->ll {
        ll start = 0, mid, end = n * (ll)(*min_element(times.begin(), times.end()));
        while(start <= end)
        {
            mid = (start + end) / 2;
            ll sum = 0;
            for(auto& time : times) sum += mid / (ll)time;
            if (sum < n) start = mid + 1;
            else end = mid - 1;
        }
        return start;
    };
    ll answer = bound();
    return answer;
}