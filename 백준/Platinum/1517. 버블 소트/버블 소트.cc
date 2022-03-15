#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> sorted;
long long ans = 0;

void merge(vector<long long >& v, int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (v[i] <= v[j]) {
			sorted[k++] = v[i++];
		}
		else {
			sorted[k++] = v[j++];
			ans += (abs(k - j));
		}
	}

	if (i > mid) {
		for (l = j; l <= right; l++) {
			sorted[k++] = v[l];
		}
	}
	else {
		for(l = i; l <= mid; l++) {
			sorted[k++] = v[l];
		}
	}

	for (l = left; l <= right; l++) {
		v[l] = sorted[l];
	}
}

void mergeSort(vector<long long>& v, int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		mergeSort(v, left, mid);
		mergeSort(v, mid + 1, right);
		merge(v, left, mid, right);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i != n; i++) {
		cin >> v[i];
	}

	sorted.resize(n);
	mergeSort(v, 0, n - 1);

	cout << ans;

	return 0;
}