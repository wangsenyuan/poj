/*
 * p2135.cpp
 *
 *  Created on: 2015年5月10日
 *      Author: senyuanwang
 */


#include "p2135.h"
#include "../mincost/graph.h"

#include <iostream>

using namespace std;

namespace p2135 {

void solve(void) {
	int N, M;
	cin >> N >> M;
	mincost::init_graph(N);
	int s = 0, t = N - 1;
	int a, b, c;
	for(int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		mincost::add_edge(a - 1, b - 1, 1, c);
		mincost::add_edge(b - 1, a - 1, 1, c);
	}

	cout << mincost::min_cost_flow(s, t, 2);
}
}
