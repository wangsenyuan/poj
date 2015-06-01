/*
 * p2484.cpp
 *
 *  Created on: 2015年6月1日
 *      Author: senyuanwang
 */
#include <iostream>
#include "p2484.h"

using namespace std;

namespace p2484 {
void solve() {
	int n;
	while (true) {
		cin >> n;
		if(n == 0) {
			break;
		}
		if (n <= 2) {
			cout << "Alice" << endl;
		} else {
			cout << "Bob" << endl;
		}
	}
}
}

