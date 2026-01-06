#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

/*
找最大判断即可
*/

void solve() {
	int n, T;
	cin >> n >> T;
	vector<int> a(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	int t = *max_element(a.begin(), a.end());
	cout << max(2, (t + T - 1) / T) << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
}