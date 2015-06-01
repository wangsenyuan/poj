/*
 * p2186.cpp
 *
 *  Created on: 2015年6月1日
 *      Author: senyuanwang
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include "p2186.h"

using namespace std;

namespace p2186 {
const int MAX_N = 10000;
const int MAX_M = 50000;
const int MAX_V = MAX_N;
int N, M, V;
int A[MAX_M], B[MAX_M];
vector<int> G[MAX_V], rG[MAX_V];

vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];

void add_edge(int from, int to) {
	G[from].push_back(to);
	rG[to].push_back(from);
}

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++) {
		if (!used[G[v][i]]) {
			dfs(G[v][i]);
		}
	}
	vs.push_back(v);
}

void rdfs(int v, int k) {
	used[v] = true;
	cmp[v] = k;
	for (int i = 0; i < rG[v].size(); i++) {
		if (!used[rG[v][i]]) {
			rdfs(rG[v][i], k);
		}
	}
}

int scc() {
	memset(used, 0, sizeof(used));
	vs.clear();
	for (int v = 0; v < V; v++) {
		if (!used[v]) {
			dfs(v);
		}
	}
	memset(used, 0, sizeof(used));
	int k = 0;
	for (int i = vs.size() - 1; i >= 0; i--) {
		if (!used[vs[i]]) {
			rdfs(vs[i], k++);
		}
	}
	return k;
}

int solve_problem() {
	V = N;
	for (int i = 0; i < M; i++) {
		add_edge(A[i] - 1, B[i] - 1);
	}
	int n = scc();
	int u = 0, num = 0;
	for (int v = 0; v < V; v++) {
		if (cmp[v] == n - 1) {
			u = v;
			num++;
		}
	}

	memset(used, 0, sizeof(used));
	rdfs(u, 0);
	for (int v = 0; v < V; v++) {
		if (!used[v]) {
			return 0;
		}
	}
	return num;
}

void solve() {
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		cin >> A[i] >> B[i];
	}

	int res = solve_problem();
	cout << res << endl;
}

}

