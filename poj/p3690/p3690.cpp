/*
 * p3690.cpp
 *
 *  Created on: 2015年7月5日
 *      Author: senyuanwang
 */

#include "p3690.h"

#include <iostream>
#include <set>
#include <string>
using namespace std;

namespace p3690 {
typedef unsigned long long ull;

const int MAX_SIZE = 1000, MAX_T = 100;

int N, M, T, P, Q;

char field[MAX_SIZE][MAX_SIZE];
char patterns[MAX_T][MAX_SIZE][MAX_SIZE];

ull hash[MAX_SIZE][MAX_SIZE], tmp[MAX_SIZE][MAX_SIZE];

void compute_hash(char a[MAX_SIZE][MAX_SIZE], int n, int m) {
	const ull B1 = 9973;
	const ull B2 = 100000007;

	ull t1 = 1;
	for (int j = 0; j < Q; j++)
		t1 *= B1;

	for (int i = 0; i < n; i++) {
		ull e = 0;
		for (int j = 0; j < Q; j++)
			e = e * B1 + a[i][j];

		for (int j = 0; j + Q <= m; j++) {
			tmp[i][j] = e;
			if (j + Q < m)
				e = e * B1 - t1 * a[i][j] + a[i][j + Q];
		}
	}

	ull t2 = 1;
	for (int i = 0; i < P; i++)
		t2 *= B2;

	for (int j = 0; j + Q <= m; j++) {
		ull e = 0;
		for (int i = 0; i < P; i++)
			e = e * B2 + tmp[i][j];

		for (int i = 0; i + P <= n; i++) {
			hash[i][j] = e;
			if (i + P < n)
				e = e * B2 - t2 * tmp[i][j] + tmp[i + P][j];
		}
	}
}

int solve_problem() {
	multiset<ull> unseen;

	for (int k = 0; k < T; k++) {
		compute_hash(patterns[k], P, Q);
		unseen.insert(hash[0][0]);
	}

	compute_hash(field, N, M);

	for (int i = 0; i + P <= N; i++) {
		for (int j = 0; j + Q <= M; j++) {
			unseen.erase(hash[i][j]);
		}
	}

	return T - unseen.size();
}

void solve() {
	int x = 1;
	do {
		cin >> N >> M >> T >> P >> Q;
		if (N == 0) {
			break;
		}
		string line;
		for(int i = 0; i < N; i++) {
			cin >> line;
			for(int j = 0; j < M; j++) {
				field[i][j] = line[j];
			}
		}

		for(int t = 0; t < T; t++) {
			for(int i = 0; i < P; i++) {
				cin >> line;
				for(int j = 0; j < Q; j++) {
					patterns[t][i][j] = line[j];
				}
			}
		}

		int ans = solve_problem();

		cout << "Case " << x << ": " << ans << endl;
		x += 1;
	} while (N > 0);
}
}

