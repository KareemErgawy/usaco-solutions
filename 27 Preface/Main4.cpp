/*
 ID: kareem_2
 PROG: preface
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int romanDigits[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
string letters = "IVXLCDM";
//              M, MC,  D, DC,  C, CX,  L, LX,  X, XI,  V, VI,  I
int add1[] = { 6, 6, 5, 5, 4, 4, 3, 3, 2, 2, 1, 1, 0 };
int add2[] = { -1, 4, -1, 4, -1, 2, -1, 2, -1, 0, -1, 0, -1 };
int counts[7];

void count(int n) {
	int rep[] = { 3, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 3 };

	for (int i = 0; i < 13; i++) {
		while (rep[i] > 0) {
			if (n - romanDigits[i] >= 0) {
				n -= romanDigits[i];
				rep[i]--;
				counts[add1[i]]++;
				if (add2[i] > -1) {
					counts[add2[i]]++;
				}
			} else {
				break;
			}
		}
	}
}

int ____main() {
	ifstream fin("preface.in");
	ofstream fout("preface.out");
	memset(counts, 0, 7 * sizeof(int));
	int n;
	fin >> n;

	for (int i = 1; i <= n; i++) {
		count(i);
	}

	for (int i = 0; i < 7; i++) {
		if (counts[i] > 0) {
			fout << letters[i] << " " << counts[i] << endl;
		}
	}

	return 0;
}
