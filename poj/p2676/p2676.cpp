/*
 * p2676.cpp
 *
 *  Created on: 2015年6月28日
 *      Author: senyuanwang
 */

#include "p2676.h"
#include <iostream>

using namespace std;

namespace p2676 {

int board[9][9];

bool checkRow(int x, int i) {
	for (int j = 0; j < 9; j++) {
		if (board[i][j] == x) {
			return false;
		}
	}
	return true;
}

bool checkCol(int x, int j) {
	for (int i = 0; i < 9; i++) {
		if (board[i][j] == x) {
			return false;
		}
	}
	return true;
}

bool checkCell(int x, int i, int j) {
	i = (i / 3) * 3;
	j = (j / 3) * 3;
	for (int m = i; m < i + 3; m++) {
		for (int n = j; n < j + 3; n++) {
			if (board[m][n] == x) {
				return false;
			}
		}
	}

	return true;
}

bool dfs(int i, int j) {
	if (i == 9) {
		return true;
	}

	int m = j == 8 ? i + 1 : i;
	int n = j == 8 ? 0 : j + 1;

	if (board[i][j] == 0) {
		for (int x = 1; x <= 9; x++) {
			if (checkRow(x, i) && checkCol(x, j) && checkCell(x, i, j)) {
				board[i][j] = x;
				if (dfs(m, n)) {
					return true;
				}
				board[i][j] = 0;
			}
		}
		if (board[i][j] == 0) {
			return false;
		}
	}

	return dfs(m, n);
}

void solve() {
	int t;
	cin >> t;

	for (int x = 0; x < t; x++) {
		for (int i = 0; i < 9; i++) {
			char s[9];
			cin >> s;
			for (int j = 0; j < 9; j++) {
				board[i][j] = s[j] - '0';
			}
		}

		dfs(0, 0);
		cout << "Scenario #" << (x + 1) << ":" << endl;
		for(int i = 0;i  < 9; i++) {
			for(int j = 0; j < 9; j++) {
				cout << board[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
}

}

