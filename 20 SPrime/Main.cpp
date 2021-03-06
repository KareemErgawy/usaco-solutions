/*
 ID: kareem_2
 PROG: sprime
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

typedef unsigned int uint;

ifstream fin("sprime.in");
ofstream fout("sprime.out");
uint n;

bool isPrime(long int n) {

	if(n == 121){
		int x = 0;
		x++;
	}

	if (n == 1) {
		return false;
	}

	if (n == 2) {
		return true;
	}

	if (n % 2 == 0) {
		return false;
	}

	for (long int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

//void generateSuperPrimes(int length, int currentDigitIndex, int* currentDigits) {
//	uint num = 0;
//	for (int i = 0; i < currentDigitIndex; i++) {
//		num = (num * 10) + currentDigits[i];
//	}
//	if (num > 0 && !isPrime(num)) {
//		return;
//	} else {
//		if (currentDigitIndex == length) {
//			fout << num << endl;
//			return;
//		}
//
//		for (int i = 1; i < 10;) {
//			currentDigits[currentDigitIndex] = i;
//			generateSuperPrimes(length, currentDigitIndex + 1, currentDigits);
//
//			switch (i) {
//			case 1:
//				i = 2;
//				break;
//			case 2:
//				i = 3;
//				break;
//			default:
//				i += 2;
//			}
//		}
//	}
//}

void generateSuperPrimes2(int length, uint current) {
	if (current != 0 && !isPrime(current)) {
		return;
	}

	if (length == 0) {
		if (isPrime(current)) {
			fout << current << endl;
		}
	} else {
		if(current == 0) {
			generateSuperPrimes2(length - 1, current * 10 + 2);
		}
		for (int i = 1; i < 10; i += 2) {
			generateSuperPrimes2(length - 1, current * 10 + i);
		}
	}
}

int main() {
	fin >> n;

//	int* currentDigits = new int[n];
	generateSuperPrimes2(n, 0);

	return 0;
}
