#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    return price >= 500'000 ? price * 0.8f : price >= 300'000 ? price * 0.9f : price >= 100'000 ? price * 0.95f : price;
}