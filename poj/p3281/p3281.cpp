/*
 * p3281.cpp
 *
 *  Created on: 2015年5月9日
 *      Author: senyuanwang
 */

#include <iostream>
#include "../maxflow/graph.h"
#include "p3281.h"

namespace p3281 {

const int MAX = 100;

int N, F, D;
bool likeF[MAX][MAX];
bool likeD[MAX][MAX];

void solve() {
	std::cin >> N >> F >> D;
	std::memset(likeF, 0, sizeof(likeF));
	std::memset(likeD, 0, sizeof(likeD));
	for (int i = 0; i < N; i++) {
		int x, y, z;
		std::cin >> x >> y;
		for (int j = 0; j < x; j++) {
			std::cin >> z;
			likeF[i][z - 1] = true;
		}
		for (int j = 0; j < y; j++) {
			std::cin >> z;
			likeD[i][z - 1] = true;
		}
	}

	int s = N * 2 + F + D, t = s + 1;

	for (int i = 0; i < F; i++) {
		maxflow::add_edge(s, N * 2 + i, 1);
	}

	for (int i = 0; i < D; i++) {
		maxflow::add_edge(N * 2 + F + i, t, 1);
	}

	for (int i = 0; i < N; i++) {
		maxflow::add_edge(i, N + i, 1);
		for (int j = 0; j < F; j++) {
			if (likeF[i][j])
				maxflow::add_edge(N * 2 + j, i, 1);
		}
		for (int j = 0; j < D; j++) {
			if (likeD[i][j])
				maxflow::add_edge(N + i, N * 2 + F + j, 1);
		}
	}

	std::cout << maxflow::max_flow(s, t);
}
}

