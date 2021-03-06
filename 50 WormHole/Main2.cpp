/*
 ID: kareem_2
 PROG: wormhole
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int n;
int* x;
int* y;
int* right_neighbor;
int* pairrings;

bool isCyclic() {
	for (int i = 1; i <= n; i++) {
		int current = i;
		while (true) {
			if (right_neighbor[current] == 0) {
				break;
			}

			current = pairrings[right_neighbor[current]];

			if (current == i) {
				return true;
			}
		}
	}

	return false;
}

int solve() {
	int i;
	for (i = 1; i <= n; i++) {
		if (pairrings[i] == 0) {
			break;
		}
	}

	if (i == n + 1) {
		if (isCyclic()) {
			return 1;
		} else {
			return 0;
		}
	}

	int total = 0;

	for (int j = i + 1; j <= n; j++) {
		if (pairrings[j] == 0) {
			pairrings[i] = j;
			pairrings[j] = i;
			total += solve();
			pairrings[i] = pairrings[j] = 0;
		}
	}

	return total;
}

int main() {
	ifstream fin("wormhole.in");
	ofstream fout("wormhole.out");
	fin >> n;
	x = new int[n + 1];
	y = new int[n + 1];
	right_neighbor = new int[n + 1];
	pairrings = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		fin >> x[i] >> y[i];
		right_neighbor[i] = 0;
		pairrings[i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i] < x[j] && y[i] == y[j]) {
				if (right_neighbor[i] == 0 || (x[j] - x[i])
						< (x[right_neighbor[i]] - x[i])) {
					right_neighbor[i] = j;
				}
			}
		}
	}

	fout << solve() << endl;

	return 0;
}
