/*
 * p2311.cpp
 *
 *  Created on: 2015年6月1日
 *      Author: senyuanwang
 */

#include "p2311.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

namespace p2311 {
const int MAX_W = 200;
int mem[MAX_W + 1][MAX_W + 1];

int grundy(int w, int h) {
	if (mem[w][h] >= 0)
		return mem[w][h];

	set<int> s;
	for (int i = 2; w - i >= 2; i++) {
		s.insert(grundy(i, h) ^ grundy(w - i, h));
	}

	for (int i = 2; h - i >= 2; i++) {
		s.insert(grundy(w, i) ^ grundy(w, h - i));
	}

	int res = 0;
	while (s.count(res)) {
		res++;
	}
	return mem[w][h] = res;
}

void solve() {
	for (int i = 0; i <= MAX_W; i++) {
		fill(mem[i], mem[i] + MAX_W + 1, -1);
	}
	int w, h;
	while (scanf("%d %d", &w, &h) == 2) {
		if (grundy(w, h) != 0) {
			cout << "WIN" << endl;
		} else {
			cout << "LOSE" << endl;
		}
	}
}
}

