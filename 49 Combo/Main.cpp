/*
 ID: kareem_2
 PROG: combo
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Calculates the number of intersecting values between f and m
// For example, if n = 50, f = 6, and m = 6 the function returns 5
// Another example, if n = 50, f = 6, and m = 4 the function returns 3
int intersect(int n, int f, int m) {
	// if the dial (n) is smaller than 5 we just return n, because all values on the dial intersect with all other values.
	if (n < 5) {
		return n;
	} else if (diff < 5) {
		int diff = f - m;

		if (diff < 0) {
			diff = -diff;
		}

		// take care of the wrap-around case
		if (n - diff < diff) {
			diff = n - diff;
		}
		return 5 - diff;
	}

	return 0;
}

int main() {

	ifstream fin("combo.in");
	ofstream fout("combo.out");

	int n;
	int f[3];
	int m[3];

	fin >> n;
	fin >> f[0] >> f[1] >> f[2];
	fin >> m[0] >> m[1] >> m[2];
	// total number of possible near combinations WITHOUT taking intersection in consideration (yet)
	int total = 2 * pow(min(5, n), 3);

	// from total subtract the intersecting combinations
	fout << (total - (intersect(n, f[0], m[0]) * intersect(n, f[1], m[1])
			* intersect(n, f[2], m[2]))) << endl;

	return 0;
}
