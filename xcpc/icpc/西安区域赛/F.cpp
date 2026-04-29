#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;
typedef pair<int, int> PII;

void solve() {
	int n;
	cin >> n;
	vector<int> to(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> to[i];
	}

	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		a[i] *= 2;
	}

	vector<int> dir(n + 1);
	for(int i = 1; i <= n; i ++) {
		if(a[to[i]] > a[i]) {
			dir[i] = 1;
		} else {
			dir[i] = -1;
		}
	}

	priority_queue<PII, vector<PII>, greater<PII>> heap;
	vector<vector<int>> adj(n + 1);
	for(int i = 1; i <= n; i ++) {
		int x = i, y = to[i];
		adj[y].emplace_back(x);
		if(dir[x] == -dir[y]) {
			heap.push({abs(a[x] - a[y]) / 2, x});
		}
	}

	vector<int> ans(n + 1, -1);
	vector<int> pos(n + 1);
	while(heap.size()) {
		auto [t, x] = heap.top();
		heap.pop();

		if(ans[x] != -1) {
			continue;
		}

		int y = to[x];
		if(ans[y] != -1) {
			int T = abs(pos[y] - a[x]);
			if(T != t) {
				continue;
			}
		}

		ans[x] = t;
		pos[x] = a[x] + dir[x] * t;
		for(auto y : adj[x]) {
			heap.push({abs(a[y] - pos[x]), y});
		}
	}

	for(int i = 1; i <= n; i ++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}