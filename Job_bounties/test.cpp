/*
* @Author: kabbo
* @Date:   2020-06-24 08:40:07
* @Last Modified by:   kabbo
* @Last Modified time: 2020-06-24 08:49:58
*/
#include<bits/stdc++.h>
using namespace std;
#define pii pair<long long,long long>
#define endl '\n'
#define ll unsigned long long


const int mod = 1e9 + 7;
using u64 = uint64_t;
using u128 = __uint128_t;
#define sc1(x) scanf("%lld",&(x));
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
/*Well, probably you won't understand anything,
because you didn't try to understand anything in your life,
you expect all hard work to be done for you by someone else.
Let's start*/


void solve() {
	string str;
	cin >> str;
	int n = str.size();
	vector<int>dp(n + 1, 0);
	for (int i(1); i < n; ++i) {
		if (str[i] == ')') {
			int left = i - dp[i - 1] - 1;
			if (left >= 0 and str[left] == '(') {
				dp[i] += (2 + dp[i - 1]);
			}
			if (left - 1 >= 0)dp[i] += dp[left - 1];
		}
	}
	cout << *max_element(dp.begin(), dp.end()) << endl;
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// int t;
	// cin >> t;
	// for (int i(1); i <= t; ++i) {
	//printf("Case %d:\n", i);
	solve();
	//}
	return 0;
}