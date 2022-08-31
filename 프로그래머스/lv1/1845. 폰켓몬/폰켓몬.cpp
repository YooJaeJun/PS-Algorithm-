#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> dic;
    for(auto& num : nums) dic[num]++;
	return min(dic.size(), nums.size() / 2);
}