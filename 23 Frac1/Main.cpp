/*
 ID: kareem_2
 PROG: frac1
 LANG: C++
 */
#include <iostream>
#include <fstream>
using namespace std;

unsigned long long gcd(unsigned long long n, unsigned long long m) {
	if (n < m) {
		unsigned long long tmp = n;
		n = m;
		m = tmp;
	}

	if (n % m == 0) {
		return m;
	}

	return gcd(m, n % m);
}

unsigned long long lcm(unsigned long long n, unsigned long long m) {
	return n / gcd(n, m) * m;
}

int _main() {
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");

	int n;
	fin >> n;
	//	fout << "0/1" << endl;
	//	for (int i = 1; i < n; i++) {
	//		//		if (gcd(i, n) == 1) {
	//		//			fout << i << "/" << n << endl;
	//		//		}
	//		float d1 = (float) i / (float) n;
	//		float d3 = (float) (i + 1) / (float) n;
	//		int j = i;
	//		int k = n;
	//		float d2 = d1;
	//		while (d2 < d3) {
	//			//			if (gcd(j, k) == 1) {
	//			fout << j << "/" << k << endl;
	//			//			}
	//			float p1 = (float) (j + 1) / (float) k;
	//			float p2 = (float) j / (float) (k - 1);
	//			if (p1 < p2) {
	//				j++;
	//			} else {
	//				k--;
	//			}
	//			d2 = (float) j / (float) k;
	//		}
	//
	//		//		for (int j = 1; j < n - 1; ) {
	//		//			for (int k = n - 1; k >= 1; ) {
	//		//				float d2 = (float) j / (float) k;
	//		//				if (d2 > d1 && d2 <= d3) {
	//		//					if (gcd(j, k) == 1 && (j != k)) {
	//		//						fout << j << "/" << k << endl;
	//		//					}
	//		//				}
	//		//			}
	//		//		}
	//	}
	//	fout << "1/1" << endl;

	int* numerators = new int[n];
	for (int i = 0; i < n; i++) {
		numerators[i] = 1;
	}

	fout << "0/1" << endl;
	if (n == 1) {
		fout << "1/1" << endl;
	}
	for (int i = 1; i < n; i++) {
		if (gcd(n, i) == 1) {
			fout << i << "/" << n << endl;
		}
		float d3 = (float) (i + 1) / (float) n;
		bool found = false;
		do {
			int minDenominator;
			float minD = 1;
			found = false;
			for (int j = 1; j < n; j++) {
				float d2 = (float) numerators[j] / (float) j;
				if (d2 <= d3 && d2 <= minD) {
					found = true;
					minDenominator = j;
					minD = d2;
				}
			}

			if (found) {
				if (gcd(minDenominator, numerators[minDenominator]) == 1) {
					fout << numerators[minDenominator] << "/" << minDenominator
							<< endl;
				}
				numerators[minDenominator]++;
			}
		} while (found);
	}

	//	unsigned long long res = 1;
	//	unsigned long long n = 50;
	//	for (unsigned long long i = 1; i <= n; i++) {
	//		res = lcm(res, i);
	//	}
	//
	//	fout << res << endl;
	//
	//	unsigned long long currentGCD;
	//	for (unsigned long long i = 1; i <= res; i++) {
	//		currentGCD = gcd(res, i);
	//		if (res / currentGCD <= n) {
	//			fout << i / currentGCD << "/" << res / currentGCD << endl;
	//		}
	//	}

	return 0;
}
