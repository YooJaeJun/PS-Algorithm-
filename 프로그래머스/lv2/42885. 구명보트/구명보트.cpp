#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    
    int siz = people.size();
    int boat = 0;
    vector<bool> inBoat(siz, false);
    int i = 0, j = siz - 1;
    
    while (i <= j)
    {
        if(inBoat[i] == false)
        {
            if(people[i] + people[j] <= limit)
            {
                inBoat[i++] = true;
            }   
            ++boat;
            inBoat[j--] = true;
        }
        else
        {
            ++i;
        }
    }
    return boat;
}