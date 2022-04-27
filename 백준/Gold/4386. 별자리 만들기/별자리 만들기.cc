#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> parent;

int getParent(int n) {
	if (parent[n] == n) return n;
	return parent[n] = getParent(parent[n]);
}

void unionParent(int n1, int n2) {
	n1 = getParent(n1);
	n2 = getParent(n2);
	if (n1 < n2) parent[n2] = n1;
	else parent[n1] = n2;
}

bool findParent(int n1, int n2) {
	n1 = getParent(n1);
	n2 = getParent(n2);
	return n1 == n2;
}

struct edge {
	int n1, n2;
	float c;
	edge(int _n1, int _n2, float _c) :
		n1(_n1), n2(_n2), c(_c) {}
	bool operator<(edge ed) {
		return c < ed.c;
	}
};

struct coords {
	float x, y;
	coords(float _x, float _y) : 
		x(_x), y(_y) {}
};

float getDistance(coords n1, coords n2) {
	return sqrtf((n1.x - n2.x) * (n1.x - n2.x) + (n1.y - n2.y) * (n1.y - n2.y));
}

void solution() {
	int n;
	cin >> n;

	vector<coords> stars;
	for (int i = 1; i <= n; i++) {
		float x, y;
		cin >> x >> y;
		stars.push_back(coords(x, y));
	}

	vector<vector<float>> dist(n + 1, vector<float>(n + 1));
	vector<edge> starEdge;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == 0) {
				dist[i][j] = getDistance(stars[i - 1], stars[j - 1]);
				starEdge.push_back(edge(i, j, dist[i][j]));
			}
		}
	}

	sort(starEdge.begin(), starEdge.end());

	parent = vector<int>(n + 1);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	float sum = 0;
	for (int i = 0; i != starEdge.size(); i++) {
		if (false == findParent(starEdge[i].n1, starEdge[i].n2)) {
			sum += starEdge[i].c;
			unionParent(starEdge[i].n1, starEdge[i].n2);
		}
	}
	printf("%.2f", sum);
}

int main() {
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}