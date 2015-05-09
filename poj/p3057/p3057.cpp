/*
 * p3057.cpp
 *
 *  Created on: 2015年5月9日
 *      Author: senyuanwang
 */

#include <iostream>
#include <vector>
#include <queue>
#include "p3057.h"
#include "../bipartite/graph.h"

using namespace std;

namespace p3057 {
int V;
const int dx[4] = { -1, 0, 0, 1 }, dy[4] = { 0, -1, 1, 0 };

const int MAX_X = 12, MAX_Y = 12;
char field[MAX_X][MAX_Y + 1];

int X, Y;
int dist[MAX_X][MAX_Y][MAX_X][MAX_Y];

vector<int> dX, dY;
vector<int> pX, pY;

bool C(int t) {
	int d = dX.size(), p = pX.size();
	V = t * d + p;

	bipartite::init_graph(V);

	for (int v = 0; v < V; v++)
		bipartite::clear_graph(v);
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < p; j++) {
			if (dist[dX[i]][dY[i]][pX[j]][pY[j]] >= 0) {
				for (int k = dist[dX[i]][dY[i]][pX[j]][pY[j]]; k <= t; k++) {
					bipartite::add_edge((k - 1) * d + i, t * d + j);
				}
			}
		}
	}

	return bipartite::bipartite_matching() == p;
}

void bfs(int x, int y, int d[MAX_X][MAX_Y]) {
	queue<int> qx, qy;
	d[x][y] = 0;
	qx.push(x);
	qy.push(y);

	while (!qx.empty()) {
		x = qx.front();
		qx.pop();
		y = qy.front();
		qy.pop();
		for (int k = 0; k < 4; k++) {
			int x2 = x + dx[k], y2 = y + dy[k];
			if (0 <= x2 && x2 < X && 0 <= y2 && y2 < Y && field[x2][y2] == '.'
					&& d[x2][y2] < 0) {
				d[x2][y2] = d[x][y] + 1;
				qx.push(x2);
				qy.push(y2);
			}
		}
	}
}

void solveOneCase() {
	int n = X * Y;
	dX.clear();
	dY.clear();
	pX.clear();
	pY.clear();
	memset(dist, -1, sizeof(dist));

	for (int x = 0; x < X; x++) {
		for (int y = 0; y < Y; y++) {
			if (field[x][y] == 'D') {
				dX.push_back(x);
				dY.push_back(y);
				bfs(x, y, dist[x][y]);
			} else if (field[x][y] == '.') {
				pX.push_back(x);
				pY.push_back(y);
			}
		}
	}

	int lb = -1, ub = n + 1;
	while (ub - lb > 1) {
		int mid = (lb + ub) / 2;
		if (C(mid))
			ub = mid;
		else
			lb = mid;
	}
	if (ub > n) {
		cout << "impossible" << endl;
	} else {
		cout << ub << endl;
	}
}

void solve() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> X >> Y;
		for (int i = 0; i < X; i++) {
			for (int j = 0; j < Y; j++) {
				cin >> field[i][j];
			}
		}
		solveOneCase();
	}
}
}

