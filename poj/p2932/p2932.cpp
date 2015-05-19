/*
 * p2932.cpp
 *
 *  Created on: 2015年5月18日
 *      Author: senyuanwang
 */

#include "p2932.h"

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

namespace p2932 {
const int MAX_N = 40000;
int N;
double x[MAX_N], y[MAX_N], r[MAX_N];

bool inside(int i, int j) {
	double dx = x[i] - x[j], dy = y[i] - y[j];
	return dx * dx + dy * dy <= r[j] * r[j];
}

void solve_problem() {
	vector<pair<double, int> > events;
	for (int i = 0; i < N; i++) {
		events.push_back(make_pair(x[i] - r[i], i)); //left point
		events.push_back(make_pair(x[i] + r[i], i + N)); //right point
	}

	sort(events.begin(), events.end());

	set<pair<double, int> > outers;
	vector<int> res;

	for (int i = 0; i < events.size(); i++) {
		int id = events[i].second % N;
		if (events[i].second < N) {
			set<pair<double, int> >::iterator it = outers.lower_bound(make_pair(y[id], id));
			if (it != outers.end() && inside(id, it->second))
				continue;
			if (it != outers.begin() && inside(id, (--it)->second))
				continue;
			res.push_back(id);
			outers.insert(make_pair(y[id], id));
		} else {
			outers.erase(make_pair(y[id], id));
		}
	}

	sort(res.begin(), res.end());

	cout << res.size() << endl;
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] + 1;
		if(i + 1 == res.size()) {
			cout << endl;
		} else {
			cout << " ";
		}
	}
}

void solve(void) {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> r[i] >> x[i] >> y[i];
	}

	solve_problem();
}
}

