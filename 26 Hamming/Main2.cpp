/*
 ID: kareem_2
 PROG: hamming
 LANG: C++
 */
#include <iostream>
#include <fstream>
using namespace std;

int n;
int d;
int maxVal;
int** distances;
int* solution;
ofstream fout("hamming.out");

int calculateDistance2(int x, int y) {
	int xOr = x ^ y;
	int distance = 0;
	while (xOr != 0) {
		xOr = (xOr ^ (xOr & -xOr));
		distance++;
	}
	return distance;
}

void search(int index, int start) {
	if (index == n) {
		fout << solution[0];
		for (int i = 1; i < n; i++) {
			if (i % 10 == 0) {
				fout << endl;
			} else {
				fout << " ";
			}
			fout << solution[i];
		}
		fout << endl;

		return;
	}

	int i, j;
	for (i = start; i < maxVal; i++) {
		for (j = 0; j < index; j++) {
			if (distances[solution[j]][i] < d) {
				break;
			}
		}

		if(j >= index){
			break;
		}
	}

	if (i < maxVal) {
		solution[index] = i;
		search(index + 1, i + 1);
	}
}

int main() {
	int b;
	ifstream fin("hamming.in");

	fin >> n >> b >> d;
	maxVal = 1 << b;
	distances = new int*[maxVal];

	for (int i = 0; i < maxVal; i++) {
		distances[i] = new int[maxVal];
		for (int j = i + 1; j < maxVal; j++) {
			distances[i][j] = calculateDistance2(i, j);
		}
	}

	solution = new int[n];
	solution[0] = 0;
	search(1, 1);

	return 0;
}
