#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<i64> a(n), b(n), c(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i ++) {
		cin >> b[i];
	}
	for(int i = 0; i < n; i ++) {
		cin >> c[i];
	}

	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	sort(c.begin(), c.end());
	reverse(c.begin(), c.end());

	set<array<i64, 3>> S;

	priority_queue<array<i64, 4>, vector<array<i64, 4>>, greater<array<i64, 4>>> heap;
	heap.push({a[n - 1] * b[n - 1] * c[n - 1], n - 1, n - 1, n - 1});
	while(heap.size() && m) {
		auto [v, d0, d1, d2] = heap.top();
		heap.pop();


		if(S.count({d0, d1, d2})) {
			continue;
		}
		S.insert({d0, d1, d2});
		m --;
		// cout << d0 << ' ' << d1 << ' ' << d2 << '\n';
		cout << v << ' ';

		if(d0 > 0) {
			heap.push({a[d0 - 1] * b[d1] * c[d2], d0 - 1, d1, d2});
		}
		if(d1 > 0) {
			heap.push({a[d0] * b[d1 - 1] * c[d2], d0, d1 - 1, d2});
		}
		if(d2 > 0) {
			// cerr << d0 << ' '<< d1 << ' ' << d2 - 1 << '\n';
			heap.push({a[d0] * b[d1] * c[d2 - 1], d0, d1, d2 - 1});
		}
	}

	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
}