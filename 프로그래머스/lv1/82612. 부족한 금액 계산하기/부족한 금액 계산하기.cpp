using namespace std;

long long solution(int price, int money, int count) {
    long long answer = -1;
    int coef = 1;
    long long sum = (static_cast<long long>(count) * (price + price * count)) / 2;    //등차수열 합 공식
    answer = money - sum;
    if (answer > 0) {
        answer = 0;
    }
    return -answer;
}