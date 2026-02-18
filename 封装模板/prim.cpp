#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;

void solve() {
    int n;
	cin >> n;
	vector w(n + 1, vector(n + 1, 0));
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			cin >> w[i][j];
		}
	}

	int res = 0;
	vector<int> st(n + 1), dist(n + 1, inf);
	dist[1] = 0;

	for(int i = 0; i < n; i ++) {
		int cur = -1;
		for(int j = 1; j <= n; j ++) {
			if(!st[j] && (cur == -1 || dist[j] < dist[cur])) {
				cur = j;
			}
		}

		st[cur] = true;	
		res += dist[cur];

		for(int j = 1; j <= n; j ++) {
			dist[j] = min(dist[j], w[cur][j]);
		}
	}

	cout << res << '\n';
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