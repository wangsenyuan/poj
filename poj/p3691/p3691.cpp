/*
 * p3691.cpp
 *
 *  Created on: 2015年7月5日
 *      Author: senyuanwang
 */

#include "p3691.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

namespace p3691 {
const int INF = 1 << 30;
const char *AGCT = "AGCT";
const int MAX_N = 50, MAX_STATE = 1 << 10, MAX_LEN_S = 1000;
int N;
string S, P[MAX_N];

int next[MAX_STATE][4];
bool ng[MAX_STATE];

int dp[MAX_LEN_S + 1][MAX_STATE];

int solve_problem() {
	vector<string> pfx;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= P[i].length(); j++) {
			pfx.push_back(P[i].substr(0, j));
		}
	}

	sort(pfx.begin(), pfx.end());
	pfx.erase(unique(pfx.begin(), pfx.end()), pfx.end());
	int K = pfx.size();
//	memset(ng, 0, sizeof(bool) * K);

	for (int i = 0; i < K; i++) {
		ng[i] = false;
		for (int j = 0; j < N; j++) {
			ng[i] |= P[j].length() <= pfx[i].length()
					&& pfx[i].substr(pfx[i].length() - P[j].length(),
							P[j].length()) == P[j];
		}
		for (int j = 0; j < 4; j++) {
			string s = pfx[i] + AGCT[j];

			int k;
			for (;;) {
				k = lower_bound(pfx.begin(), pfx.end(), s) - pfx.begin();
				if (k < K && pfx[k] == s)
					break;
				s = s.substr(1);
			}
			next[i][j] = k;
		}
	}

	dp[0][0] = 1;
	for (int i = 1; i < K; i++)
		dp[0][i] = 0;

	for (int t = 0; t < S.length(); t++) {
		for (int i = 0; i < K; ++i)
			dp[t + 1][i] = INF;

		for (int i = 0; i < K; i++) {
			if (ng[i])
				continue;
			for (int j = 0; j < 4; j++) {
				int k = next[i][j];
				dp[t + 1][k] = min(dp[t + 1][k],
						dp[t][i] + (S[t] == AGCT[j] ? 0 : 1));
			}
		}
	}

	int ans = INF;
	for (int i = 0; i < K; i++) {
		if (ng[i])
			continue;
		ans = min(ans, dp[S.length()][i]);
	}

	if (ans == INF)
		return -1;
	else
		return ans;

}

void solve() {
	int t = 1;
	do {
		cin >> N;
		if (N == 0) {
			break;
		}

		for(int i = 0; i < N; i++) {
			cin >> P[i];
		}
		cin >> S;
		int ans = solve_problem();
		cout << "Case " << t << ": " <<  ans << endl;
		t += 1;
	} while (N > 0);
}
}

