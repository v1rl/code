#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int fa[N];

int find(int x) {
	if(fa[x] != x) return fa[x] = find(fa[x]);
	return fa[x];
}

void solve() {
	for(int i = 1; i <= 200000; i ++) {
		fa[i] = i;
	}
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i ++) {
		int x, y;
		cin >> x >> y;
		x = find(x), y = find(y);
		fa[y] = x;
	}

	for(int i = 1; i <= n; i ++) {
		if(fa[i] != 1) {
			cout << "No" << '\n';
			return;
		}
	}
	cout << "Yes" << '\n';
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