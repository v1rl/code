#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	string s;
	cin >> s;
	i64 sum = 0;
	for(auto c : s) {
		sum += (int)c;
	}
	cout << sum << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
}