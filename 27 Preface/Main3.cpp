/*
 ID: kareem_2
 PROG: preface
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int freq[7];

void processRoman(int n) {
	int nM = 0;
	int nD = 0;
	int nC = 0;
	int nL = 0;
	int nX = 0;
	int nV = 0;
	int nI = 0;

	while (n >= 1000) {
		n -= 1000;
		nM++;
	}

	while (n >= 500) {
		n -= 500;
		nD++;
	}

	while (n >= 100) {
		n -= 100;
		nC++;
	}

	while (n >= 50) {
		n -= 50;
		nL++;
	}

	while (n >= 10) {
		n -= 10;
		nX++;
	}

	while (n >= 5) {
		n -= 5;
		nV++;
	}

	while (n >= 1) {
		n -= 1;
		nI++;
	}

	while (nD > 0 && (nC / 4) > 0) {
		nM++;
		nD--;
		nC -= 3;
	}

	while ((nC / 4) > 0) {
		nD++;
		nC -= 3;
	}

	while (nL > 0 && (nX / 4) > 0) {
		nC++;
		nL--;
		nX -= 3;
	}

	while ((nX / 4) > 0) {
		nL++;
		nX -= 3;
	}

	while (nV > 0 && (nI / 4) > 0) {
		nX++;
		nV--;
		nI -= 3;
	}

	while ((nI / 4) > 0) {
		nV++;
		nI -= 3;
	}

	freq[6] += nM;
	freq[5] += nD;
	freq[4] += nC;
	freq[3] += nL;
	freq[2] += nX;
	freq[1] += nV;
	freq[0] += nI;
}

int ___main() {

	ifstream fin("preface.in");
	ofstream fout("preface.out");

	int n;
	fin >> n;
	memset(freq, 0, 7 * sizeof(int));

	for (int i = 1; i <= n; i++) {
		processRoman(i);
	}

	int highest;
	for (int i = 6; i >= 0; i--) {
		if (freq[i] != 0) {
			highest = i;
			break;
		}
	}

	string index = "IVXLCDM";
	for (int i = 0; i <= highest; i++) {
		fout << index[i] << " " << freq[i] << endl;
	}

	return 0;
}
