#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int ans = 0, remain = 0;
    
    while(chicken)
    {
        ans += chicken / 10;
        remain += chicken % 10;
        if (remain >= 10)
        {
            ans++;            
            chicken++;
            remain -= 10;
        }
        chicken /= 10;
    }
    
    return ans;
}