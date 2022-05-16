#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
#define int int64_t
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int max1 = 100'001;
const double mod = 1e9;


double determine(vvd m)
{
	return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
		m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
		m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
}

double changeDetermine(vvd m, vd b, int i)
{
	if (b.size() == 3) 
	{
		m[0][i] = b[0];
		m[1][i] = b[1];
		m[2][i] = b[2];
	}
	return determine(m);
}

double cramer(vvd m, vd b, int i) {
	if ((determine(m) - 0) > -DBL_EPSILON && (determine(m) - 0) < DBL_EPSILON)
		return mod;

	double ret = changeDetermine(m, b, i) / determine(m);

	if (ret > -0.0005 && ret < 0.0005) 
		return 0.0;

	return ret;
}

void solution() {
	vvd m(3, vd(3));
	vd b(3);

	for (int i = 0; i != 3; i++) 
	{
		for (int j = 0; j != 3; j++) 
		{
			scanf("%lf", &m[i][j]);
		}
		scanf("%lf", &b[i]);
	}

	printf("%lld ", (int)changeDetermine(m, b, 0));
	printf("%lld ", (int)changeDetermine(m, b, 1));
	printf("%lld ", (int)changeDetermine(m, b, 2));
	printf("%lld\n", (int)changeDetermine(m, { 0 }, 2));

	if (abs(cramer(m, b, 0) - mod) < DBL_EPSILON ||
		abs(cramer(m, b, 1) - mod) < DBL_EPSILON ||
		abs(cramer(m, b, 2) - mod) < DBL_EPSILON) 
	{
		printf("No unique solution\n");
	}
	else 
	{
		printf("Unique solution: ");
		printf("%.3lf ", cramer(m, b, 0));
		printf("%.3lf ", cramer(m, b, 1));
		printf("%.3lf\n", cramer(m, b, 2));
	}
	printf("\n");
}

int32_t main() {
	int t = 1;
	cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}