#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
按照伤害降序吃
*/

void solve() {
	int n;
	i64 k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end(), greater());
	i64 sum = accumulate(a.begin(), a.end(), 0ll);
	i64 h, x;
	cin >> h >> x;
	for(auto d : a) {
		h -= x * min(sum, k);
		if(h < 0) {
			cout << "YES" << '\n';
			return;
		}
		sum -= d;
	}

	cout << "NO" << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
}