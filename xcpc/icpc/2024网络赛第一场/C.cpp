#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
using PII = pair<int, int>;
const int inf = 1e9;

const int N = 1e6 + 10;
int p[N];

int find(int x) {
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= n + 1; i ++) {
		p[i] = i;
	}
	bool f = true;
	for(int i = 1; i <= n; i ++) {
		int l, r;
		cin >> l >> r;
		l = find(l), r = find(r + 1);
		if(l == r) {
			f = false;
		}
		p[r] = l;
	}

	cout << (f ? 1 : 0) << '\n';
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
