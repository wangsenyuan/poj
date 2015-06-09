/*
 * p2559.cpp
 *
 *  Created on: 2015年6月9日
 *      Author: senyuanwang
 */
#include "p2559.h"
#include <iostream>
#include <cmath>
using namespace std;

namespace p2559 {
const int MAX_N = 100000;
int n;
int h[MAX_N];
int L[MAX_N], R[MAX_N];
int st[MAX_N];

long long solve_problem() {
	int t = 0;
	for (int i = 0; i < n; i++) {
		while (t > 0 && h[st[t - 1]] >= h[i])
			t--;
		L[i] = t == 0 ? 0 : (st[t - 1] + 1);
		st[t++] = i;
	}

	t = 0;
	for (int i = n - 1; i >= 0; i--) {
		while (t > 0 && h[st[t - 1]] >= h[i])
			t--;
		R[i] = t == 0 ? n : st[t - 1];
		st[t++] = i;
	}

	long long res = 0;
	for(int i = 0; i < n; i++)  {
		res = max(res, (long long)h[i] * (R[i] - L[i]));
	}

	return res;
}

void solve() {
	do {
		cin >> n;
		if(n == 0) {
			break;
		}
		for(int i = 0; i < n; i++) {
			cin >> h[i];
		}
		long long res = solve_problem();
		cout << res << endl;
	} while(true);
}
}

