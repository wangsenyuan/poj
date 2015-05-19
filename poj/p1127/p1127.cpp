/*
 * numbers.cpp
 *
 *  Created on: 2015年5月17日
 *      Author: senyuanwang
 */

#include <iostream>
#include <cmath>
#include "p1127.h"

using namespace std;

namespace p1127 {

double EPS = 1e-10;

double add(double a, double b) {
	if (abs(a + b) < EPS * (abs(a) + abs(b)))
		return 0.0;
	else
		return a + b;
}

struct P {
	double x, y;
	P():x(0.0), y(0.0) {
	}

	P(double x, double y) :
			x(x), y(y) {

	}

	P operator +(P p) {
		return P(add(x, p.x), add(y, p.y));
	}

	P operator -(P p) {
		return P(add(x, -p.x), add(y, -p.y));
	}

	P operator *(double d) {
		return P(x * d, y * d);
	}

	double dot(P p) {
		return add(x * p.x, y * p.y);
	}

	double det(P p) {
		return add(x * p.y, -y * p.x);
	}
};

//check if q in segment p1-p2
bool on_seg(P p1, P p2, P q) {
	return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}

P intersection(P p1, P p2, P q1, P q2) {
	return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));
}

const int MAX_N = 13, MAX_M = 10000;
int N;
P p[MAX_N], q[MAX_N];
int m;
int a[MAX_M], b[MAX_M];

bool g[MAX_N][MAX_N];

void solve_problem(void) {
	for (int i = 0; i < N; i++) {
		g[i][i] = true;
		for (int j = 0; j < i; j++) {
			if ((p[i] - q[i]).det(p[j] - q[j]) == 0) {
				g[i][j] = g[j][i] = on_seg(p[i], q[i], p[j])
						|| on_seg(p[i], q[i], q[j]) || on_seg(p[j], q[j], q[i])
						|| on_seg(p[j], q[j], q[i]);

			} else {
				P r = intersection(p[i], q[i], p[j], q[j]);
				g[i][j] = g[j][i] = on_seg(p[i], q[i], r)
						&& on_seg(p[j], q[j], r);
			}
		}
	}

//	puts("before floyd-warshall");
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				g[i][j] |= g[i][k] && g[k][j];
			}
		}
	}

	for (int i = 0; i < m; i++) {
		cout << (g[a[i]][b[i]] ? "CONNECTED" : "NOT CONNECTED") << endl;
	}
}

void solve(void) {
	cin >> N;
	while (N > 0) {
		for (int i = 0; i < N; i++) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			p[i] = P(x1, y1);
			q[i] = P(x2, y2);
		}
		int x, y;
		cin >> x >> y;
		int i = 0;
		while (x > 0 && y > 0) {
			a[i] = x - 1;
			b[i] = y - 1;
			i++;
			cin >> x >> y;
		}
		m = i;
		//	puts("before solve_problem");
		solve_problem();

		cin >> N;
	}
}
}

