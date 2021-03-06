/*
 ID: kareem_2
 PROG: milk3
 LANG: C++
 */
#include <iostream>
#include <fstream>

using namespace std;

const int NUM_STATES = 9261;
bool states[NUM_STATES];
int bucketsCapacity[3];
int bucketsCurrent[3];
bool solutions[21];

void explore() {

	if (bucketsCurrent[0] == 0) {
		//		cout << bucketsCurrent[2] << endl;
		solutions[bucketsCurrent[2]] = true;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) {
				continue;
			}

			int amount = min(bucketsCurrent[i],
					(bucketsCapacity[j] - bucketsCurrent[j]));
			bucketsCurrent[i] -= amount;
			bucketsCurrent[j] += amount;
			int index = bucketsCurrent[0] + (bucketsCurrent[1] * 21)
					+ (bucketsCurrent[2] * 21 * 21);

			if (states[index] == false) {
				states[index] = true;
				explore();
			}

			bucketsCurrent[i] += amount;
			bucketsCurrent[j] -= amount;
		}
	}
}

int _main() {
	for (int i = 0; i < NUM_STATES; i++) {
		states[i] = false;
	}

	for (int i = 0; i < 21; i++) {
		solutions[i] = false;
	}

	ifstream fin("milk3.in");
	ofstream fout("milk3.out");

	fin >> bucketsCapacity[0];
	bucketsCurrent[0] = 0;
	fin >> bucketsCapacity[1];
	bucketsCurrent[1] = 0;
	fin >> bucketsCapacity[2];
	bucketsCurrent[2] = bucketsCapacity[2];

	explore();

	bool first = true;
	for (int i = 0; i < 21; i++) {
		if (solutions[i]) {
			if (first) {
				fout << i;
				first = false;
			} else {
				fout << " " << i;
			}
		}
	}

	fout << endl;

	return 0;
}
