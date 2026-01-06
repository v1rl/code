#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

/*
将每个连通块的最大边数-实际边数累计到答案
若答案最后仍为0，则考虑连接两个最小的连通块
*/

const int N = 1e6 + 10;
int p[N], siz[N];

int find(int x) {
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		p[i] = i;
		siz[i] = 1;
	}
	vector<int> cnt(n + 1);
	for(int i = 0; i < m; i ++) {
		int x, y;
		cin >> x >> y;
		x = find(x), y = find(y);
		if(x != y) {
			p[y] = x;
			siz[x] += siz[y];
			// 需要注意，连通块内边的数量也理应在连通块合并时累加到合并点上
			cnt[x] += cnt[y];
		}
		cnt[x] ++;
	}

	i64 ans = 0;
	vector<int> st(n + 1);
	int mn = 1e9, cmn = 1e9;
	int id = -1, cid = -1;
	for(int i = 1; i <= n; i ++) {
		int x = find(i);
		if(!st[x]) {
			ans += 1ll * siz[x] * (siz[x] - 1) / 2 - cnt[x];
			if(siz[x] < mn) {
				cmn = mn, cid = id;
				mn = siz[x], id = x;
			} else if(siz[x] < cmn) {
				cmn = siz[x], cid = x;
			}
			st[x] = true;
		}
	}
	if(ans) {
		cout << ans << '\n';
	} else {
		i64 t = cmn + mn;
		int base = cnt[id] + cnt[cid];
		cout << t * (t - 1) / 2 - base << '\n';
	}
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