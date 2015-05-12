/*
 * p2175.cpp
 *
 *  Created on: 2015年5月12日
 *      Author: senyuanwang
 */

#include "p2175.h"
#include <iostream>
#include <algorithm>

using namespace std;

namespace p2175 {
const int INF = 1000000000;
const int MAX_N = 100, MAX_M = 100;
const int MAX_V = MAX_N + MAX_M + 1;

int N, M;
int X[MAX_N], Y[MAX_N], B[MAX_N];
int P[MAX_M], Q[MAX_M], C[MAX_M];
int E[MAX_N][MAX_M];

int g[MAX_V][MAX_V];
int prev[MAX_V][MAX_V];
bool used[MAX_V];

void solve(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i] >> B[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> P[i] >> Q[i] >> C[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> E[i][j];
		}
	}

	int V = N + M + 1;

	for (int i = 0; i < V; i++) {
		fill(g[i], g[i] + V, INF);
	}

	for (int j = 0; j < M; j++) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			int c = abs(X[i] - P[j]) + abs(Y[i] - Q[j]) + 1;
			g[i][N + j] = c;
			if (E[i][j] > 0)
				g[N + j][i] = -c;
			sum += E[i][j];
		}
		if (sum > 0) {
			g[N + M][N + j] = 0;
		}

		if (sum < C[j]) {
			g[N + j][N + M] = 0;
		}
	}

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			prev[i][j] = i;
		}
	}

	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (g[i][j] > g[i][k] + g[k][j]) {
					g[i][j] = g[i][k] + g[k][j];
					prev[i][j] = prev[k][j];
					if (i == j && g[i][i] < 0) {
						fill(used, used + V, false);
						for (int v = i; !used[v]; v = prev[i][v]) {
							used[v] = true;
							if (v != N + M && prev[i][v] != N + M) {
								if (v >= N) {
									E[prev[i][v]][v - N]++;
								} else {
									E[v][prev[i][v] - N]--;
								}
							}
						}
						cout << "SUBOPTIMAL" << endl;
						for (int x = 0; x < N; x++) {
							for (int y = 0; y < M; y++) {
								cout << E[x][y];
								if (y == M - 1) {
									cout << endl;
								} else {
									cout << " ";
								}
							}
						}
						return;
					}
				}
			}
		}
	}

	cout << "OPTIMAL\n";
}

}

