/*
 * p3469.cpp
 *
 *  Created on: 2015年5月10日
 *      Author: senyuanwang
 */

#include "p3469.h"
#include "../maxflow/graph.h"
#include <iostream>
using namespace std;

namespace p3469 {
const int MAX_N = 20000;
const int MAX_M = 200000;
void solve(void) {
	int n, m;
	cin >> n >> m;

	int A[MAX_N], B[MAX_N];

	for(int i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
	}

	int a[MAX_M], b[MAX_M], w[MAX_M];

	for(int i = 0; i < m; i++) {
		cin >> a[i] >> b[i] >> w[i];
	}

	int s = n, t = s + 1;

	for(int i = 0; i < n; i++) {
		maxflow::add_edge(i, t, A[i]);
		maxflow::add_edge(s, i, B[i]);
	}

	for(int i = 0; i < m; i++) {
		maxflow::add_edge(a[i] - 1, b[i] - 1, w[i]);
		maxflow::add_edge(b[i] - 1, a[i] - 1, w[i]);
	}

	cout << maxflow::max_flow(s, t) << endl;
}
}

