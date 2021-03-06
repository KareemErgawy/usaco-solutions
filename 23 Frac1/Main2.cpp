/*
 ID: kareem_2
 PROG: frac1
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct fraction {
	int numerator;
	int deominator;
};

bool relativelyPrime(int a, int b) {
	int r = a % b;

	while (r > 0) {
		a = b;
		b = r;
		r = a % b;
	}

	return (b == 1);
}

bool compareFractions(fraction f1, fraction f2) {
	return f1.numerator * f2.deominator < f2.numerator * f1.deominator;
}

int __main() {
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");
	int n;
	fin >> n;
	fraction* fractions = new fraction[n * n];
	int foundFractions = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (relativelyPrime(j, i)) {
				fractions[foundFractions].numerator = j;
				fractions[foundFractions].deominator = i;
				foundFractions++;
			}
		}
	}

	sort(fractions, fractions + foundFractions, compareFractions);

	for (int i = 0; i < foundFractions; i++) {
		fout << fractions[i].numerator << "/" << fractions[i].deominator
				<< endl;
	}

	return 0;
}
