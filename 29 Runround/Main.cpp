/*
 ID: kareem_2
 PROG: runround
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

typedef unsigned long ul;

inline int isCandidate(ul n) {
	bool visited[9];
	memset(visited, 0, sizeof(visited));
	int numDigits = 0;

	while (n) {
		int d = n % 10;
		n = n / 10;

		if (d == 0) {
			return 0;
		}

		d--;

		if (visited[d]) {
			return 0;
		}

		visited[d] = true;
		numDigits++;
	}

	return numDigits;
}

inline bool isRunaround(ul n, int numDigits) {
//	cout << n << endl;
	bool* visited = new bool[numDigits];
	int* to = new int[numDigits];
	memset(visited, 0, numDigits);
	int current = 0;

	while (n) {
		int d = n % 10;
		n = n / 10;

		int index = (d + (numDigits - 1 - current)) % numDigits;

		if (index == (numDigits - 1 - current) || visited[index]) {
			return false;
		}

		//		if(index == 0 && current < numDigits - 1) {
		//			return false;
		//		}

		visited[index] = true;
		to[numDigits - 1 - current] = index;
		current++;
	}

	current = 0;
	for (int i = 0; current < numDigits;) {
		i = to[i];
		current++;
		if ((i == 0) && (current < numDigits)) {
			return false;
		}
	}

	return true;
}

int main() {
	ifstream fin("runround.in");
	ofstream fout("runround.out");

	ul n = 10;
//	fin >> n;

	for (ul i = n + 1;; i++) {
		int size = isCandidate(i);
		if (size) {
			if (isRunaround(i, size)) {
				cout << i << endl;
				break;
			}
		}
	}

	return 0;
}
