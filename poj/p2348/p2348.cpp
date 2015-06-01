/*
 * p2348.cpp
 *
 *  Created on: 2015年6月1日
 *      Author: senyuanwang
 */
#include <iostream>
#include "p2348.h"

using namespace std;

namespace p2348 {

bool play(int a, int b) {
	bool f = true;
	while (true) {
		if (a > b) {
			int c = a;
			a = b;
			b = c;
		}
		if (b % a == 0 || b - a > a) {
			break;
		}
		b -= a;
		f = !f;
	}
	return f;
}

void solve() {
	int a, b;
	while (true) {
		cin >> a >> b;
		if (a == b && b == 0) {
			break;
		}
		bool win = play(a, b);
		if (win) {
			cout << "Stan wins" << endl;
		} else {
			cout << "Ollie wins" << endl;
		}
	}

}
}

