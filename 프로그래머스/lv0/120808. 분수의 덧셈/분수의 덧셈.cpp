#include <string>
#include <vector>
#include <functional>

using namespace std;

vector<int> solution(int denum1, int num1, int denum2, int num2) {
    function<int(int, int)> gcd = [&](int a, int b)
    {
        if (b == 0) return a;
        return gcd(b, a % b);
    };
    
    auto lcm = [&](int a, int b)
    {
        return a * b / gcd(a, b);
    };
    
    int l = lcm(num1, num2);
    int bottom = l;
    int top = denum1 * l / num1 + denum2 * l / num2;
    
    int g = gcd(top, bottom);
    bottom /= g;
    top /= g;
    
    return {top, bottom};
}