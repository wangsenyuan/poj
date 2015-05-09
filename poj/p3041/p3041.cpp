/*
 * main.cpp
 *
 *  Created on: 2015年5月6日
 *      Author: senyuanwang
 */

#include <iostream>
#include <vector>
#include "p3041.h"
using namespace std;

namespace p3041 {
const int MAX_N = 1000;

vector<int> G[MAX_N];
int match[MAX_N];
bool used[MAX_N];
void add_edge(int i, int j) {
	G[i].push_back(j);
	G[j].push_back(i);
}

bool dfs(int v, int match[], bool used[]) {
	used[v] = true;

	for (int j = 0; j < G[v].size(); j++) {
		int u = G[v][j];
		int w = match[u];
		if (w < 0 || (!used[w] && dfs(w, match, used))) {
			match[u] = v;
			match[v] = u;
			return true;
		}
	}
	return false;
}

int bipartite_matching(int n) {
	int res = 0;
	memset(match, -1, sizeof(match));
	for (int v = 0; v < 2 * n; v++) {
		if (match[v] < 0) {
			memset(used, 0, sizeof(used));
			if (dfs(v, match, used)) {
				res += 1;
			}
		}
	}
	return res;
}

}
void solve3041(void) {
	int n, m;

	cin >> n >> m;

	int r, c;
	for (int i = 0; i < m; i++) {
		cin >> r >> c;
		p3041::add_edge(r - 1, c + n - 1);
	}

	cout << p3041::bipartite_matching(n);
}

