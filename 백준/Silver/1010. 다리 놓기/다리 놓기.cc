#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

#define MAXINT 30
int pas[MAXINT + 1][MAXINT + 1];

void bridge() {
	//조합: nCk = nPk/k! = n!/(k!(n-k)!) 으론 오버플로
	//파스칼 삼각형: 행렬 (n, k) =  (n - 1, k - 1) + (n - 1, k)
	pas[0][0] = 1;
	for (int i = 1; i <= MAXINT; i++) {
		pas[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			pas[i][j] = pas[i - 1][j - 1] + pas[i - 1][j];
		}
	}
}
int main() {
	bridge();	//파스칼 삼각형 세팅
	int t;
	cin >> t;
	int n1, n2;
	for (int i = 0; i != t; i++) {
		cin >> n1 >> n2;
		printf("%d\n", pas[n2][n1]);
	}
	return 0;
}