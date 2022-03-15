#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int compare(const void* a, const void* b) {
	if (*(int*)a > *(int*)b) { return 1; }
	else if (*(int*)a < *(int*)b) { return -1; }
	return 0;
}

int bound(int arr[], int num, int size, char upperOrLower) {
	int start = 0;
	int end = size;

	if (upperOrLower == 'u') {
		while (start < end) {
			int mid = (start + end) / 2;
			if (arr[mid] > num) {
				end = mid;
			}
			else {
				start = mid + 1;
			}
		}
	}
	else if (upperOrLower == 'l') {
		while (start < end) {
			int mid = (start + end) / 2;
			if (arr[mid] >= num) {
				end = mid;
			}
			else {
				start = mid + 1;
			}
		}
	}
	return end;
}

int main() {
	int n;
	scanf("%d", &n);
	int* arr = new int[n]();
	for (int i = 0; i != n; i++) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, n, sizeof(int), compare);

	int m;
	scanf("%d", &m);
	vector<int> arr2(m);
	for (int i = 0; i != m; i++) {
		scanf("%d", &arr2[i]);
		printf("%d ", bound(arr, arr2[i], n, 'u') - bound(arr, arr2[i], n, 'l'));
	}

	delete[] arr;
	return 0;
}