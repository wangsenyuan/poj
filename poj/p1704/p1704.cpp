/*
 * p1704.cpp
 *
 *  Created on: 2015年6月1日
 *      Author: senyuanwang
 */
#include "p1704.h"
#include <iostream>
#include <algorithm>

using namespace std;

namespace p1704 {
const int MAX_N = 1000;
int N, P[MAX_N];

bool solve_problem() {
	if (N % 2 == 1)
		P[N++] = 0;
	sort(P, P + N);

	int x = 0;
	for (int i = 0; i + 1 < N; i += 2) {
		x ^= (P[i + 1] - P[i] - 1);
	}

	return x == 0;
}

void solve() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		cin >> N;
		for(int j = 0; j < N; j++) {
			cin >> P[j];
		}
		bool res = solve_problem();
		if(res) {
			cout << "Bob will win" << endl;
		} else {
			cout << "Georgia will win" << endl;
		}
	}
}
}

