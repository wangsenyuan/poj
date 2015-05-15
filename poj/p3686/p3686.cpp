/*
 * p3686.cpp
 *
 *  Created on: 2015年5月15日
 *      Author: senyuanwang
 */

#include "p3686.h"
#include "../mincost/graph.h"
#include <iostream>

using namespace std;

namespace p3686 {
const int MAX_N = 50, MAX_M = 50;
int N, M;
int Z[MAX_N][MAX_M];

void solve_one_case(void) {
	int s = N + N * M, t = s + 1;
	mincost::init_graph(t + 1);
	for(int i = 0; i < N; i++) {
		mincost::add_edge(s, i, 1, 0);
	}

	for(int j = 0; j < M; j++) {
		for(int k = 0; k < N; k++) {
			mincost::add_edge(N + j * N + k, t, 1, 0);
			for(int i = 0; i < N; i++) {
				mincost::add_edge(i, N + j * N + k, 1, (k + 1) * Z[i][j]);
			}
		}
	}

	printf("%.6f\n", (double) mincost::min_cost_flow(s, t , N) / N);
}

void solve(void) {
	int T;
	cin >> T;

	for(int t = 0; t < T; t++) {
		cin >> N >> M;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				cin >> Z[i][j];
			}
		}

		solve_one_case();
	}
}
}


