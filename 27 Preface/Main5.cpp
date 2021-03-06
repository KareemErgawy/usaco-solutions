/*
 ID: kareem_2
 PROG: preface
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {

	ifstream fin("preface.in");
	ofstream fout("preface.out");
	int counts2[7];
	memset(counts2, 0, 7 * sizeof(int));
	int n;
	fin >> n;
	int factors[6] = { 5, 2, 5, 2, 5, 2 };
	for (int i = 1; i <= n; i++) {
		for (int j = 0, temp = i; temp > 0; j++) {

			if (temp % factors[j] > 3) {
				counts2[j]++;
				if ((temp / factors[j] > 0) && i % factors[j + 2] > factors[j
						+ 1]) {
					counts2[j + 2]++;
				} else {
					counts2[j + 1]++;
				}
			} else {
				counts2[j] += temp % factors[j];
			}

			temp /= factors[j];
		}
	}

	for (int i = 0; i < 7; i++) {
		if (counts2[i] > 0) {
			cout << "IVXLCDM"[i] << " " << counts2[i] << endl;
		}
	}

	return 0;
}
