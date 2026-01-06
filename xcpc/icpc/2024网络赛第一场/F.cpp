#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
using PII = pair<int, int>;
const int inf = 1e9;

/*
循环找最低点，将周围所有更低的点累加到答案中，之后将所有更低的点视作与当前点等高
同一块内所有点的属性相同，后续不断合并块，考虑并查集
维护当前并查集的大小和高度
比较巧妙的是，因为所有块的都是在数组中连续的块，所以每次合并时只需要考虑左右邻点所处的并查集
将小于等于当前值的左右邻点加入并查集，不过只累加严格小于时并查集大小到答案

Trick：数组中想要维护的块是线性连续的，后续对块执行合并、跳过、累加等操作，都可以考虑使用并查集
*/

struct DSU {
	vector<int> p, siz, value;

	DSU(int n) {
		init(n);
	}

	void init(int n) {
		p.resize(n + 1);
		iota(p.begin(), p.end(), 0);
		siz.assign(n + 1, 1); 

	}

	int find(int x) {
		if(x != p[x]) p[x] = find(p[x]);
		return p[x];
	}

	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return false;
		p[y] = x;
		siz[x] += siz[y];
		return true;
	}

	int getsize(int x) {
		x = find(x);
		return siz[x];
	}
};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<array<int, 2>> b(n);
	DSU dsu(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
		b[i] = {a[i], i};
	}

	i64 ans = 0;
	sort(b.begin(), b.end());
	for(auto [_, pos] : b) {
		if(pos != 0) {
			int l = dsu.find(pos - 1);
			if(a[l] < a[pos]) {
				ans += dsu.getsize(l);
			}
			if(a[l] <= a[pos]) {
				dsu.merge(pos, l);
			}
		}
		if(pos != n - 1) {
			int r = dsu.find(pos + 1);
			if(a[r] < a[pos]) {
				ans += dsu.getsize(r);
			}
			if(a[r] <= a[pos]) {
				dsu.merge(pos, r);
			}
		}
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