/*
 * p3680.cpp
 *
 *  Created on: 2015年5月15日
 *      Author: senyuanwang
 */

#include "p3680.h"
#include "../mincost/graph.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace p3680 {

const int MAX_N = 200;
const int INF = 1 << 20;

int N, K;
int a[MAX_N], b[MAX_N], w[MAX_N];

void solve_one_case() {
	vector<int> x;
	for(int i = 0; i < N; i++) {
		x.push_back(a[i]);
		x.push_back(b[i]);
	}

	sort(x.begin(), x.end());

	x.erase(unique(x.begin(), x.end()), x.end());

	int m = x.size();
	int s = m, t = s + 1;
	mincost::init_graph(t + 1);
	int res = 0;
	mincost::add_edge(s, 0, K, 0);
	mincost::add_edge(m - 1, t, K, 0);
	for(int i = 0; i + 1 < m; i++) {
		mincost::add_edge(i, i + 1, INF, 0);
	}

	for(int i = 0; i < N; i++) {
		int u = find(x.begin(), x.end(), a[i]) - x.begin();
		int v = find(x.begin(), x.end(), b[i]) - x.begin();
		mincost::add_edge(v, u, 1, w[i]);
		mincost::add_edge(s, v, 1, 0);
		mincost::add_edge(u, t, 1, 0);
		res -= w[i];
	}

	res += mincost::min_cost_flow(s, t, K + N);
	cout << -res << endl;
}

void solve() {
	int T;
	cin >> T;

	for(int t = 0; t < T; t++) {
		cin >> N >> K;
		for(int i = 0; i < N; i++) {
			cin >> a[i] >> b[i] >> w[i];
		}
		solve_one_case();
	}
}
}


