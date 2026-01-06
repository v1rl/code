#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
using PII = pair<int, int>;

void solve() {
	int n, m;
	cin >> n >> m;
	priority_queue<PII> heap;
	vector<int> a(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
		heap.push({a[i] * m, i});
	}

	int ans = 0;
	int t = 0;
	while(m --) {
		n --;
		auto [w, id] = heap.top();
		ans += w - t * a[id];
		// cout << ans << '\n';
		heap.pop();
		t ++;
		if(n == 0) break;
	}

	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
	return 0;
}