#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 4e4 + 10, M = 2010;
int bel[N], pos[N];
vector<int> a(N);
vector<int> kth(N);
int rk[N];
int L[M], R[M];
int f[M][M];
int g[M][M];
vector<vector<int>> bk(N);

int krank(int x) {
	return lower_bound(kth.begin() + 1, kth.end(), x) - kth.begin();
}

int query(int l, int r) {
	int x = bel[l], y = bel[r];
	if(x == y) {
		unordered_map<int, int> mp;
		int mx = 0;
		int res = -1;
		for(int i = l; i <= r; i ++) {
			mp[rk[i]] ++;
		}
		for(auto [num, t] : mp) {
			if(t > mx) {
				mx = t;
				res = num;
			}
			else if(t == mx) {
				res = min(res, num);
			}
		}
		return kth[res];
	}
	int mx = f[x + 1][y - 1];
	int res = g[x + 1][y - 1];
	for(int i = l; i <= R[x]; i ++) {
		while(pos[i] + mx < bk[rk[i]].size() && bk[rk[i]][pos[i] + mx] <= r) {
			mx ++;
			res = rk[i];
		}
		if(pos[i] + mx - 1 >= 0 && pos[i] + mx - 1 < bk[rk[i]].size() && bk[rk[i]][pos[i] + mx - 1] <= r) {
			res = min(res, rk[i]);
		}
	}
	for(int i = L[y]; i <= r; i ++) {
		while(pos[i] - mx >= 0 && bk[rk[i]][pos[i] - mx] >= l) {
			mx ++;
			res = rk[i];
		}
		if(pos[i] - mx + 1 >= 0 && pos[i] - mx + 1 < bk[rk[i]].size() && bk[rk[i]][pos[i] - mx + 1] >= l) {
			res = min(res, rk[i]);
		}
	}
	return kth[res];
}

void build(int n) {
	int len = sqrt(n);
	int tot = (n + len - 1) / len;
	for(int i = 1; i <= n; i ++) {
		bel[i] = (i - 1) / len + 1;
	}
	for(int i = 1; i <= tot; i ++) {
		L[i] = (i - 1) * len + 1;
		R[i] = min(i * len, n);
	}
	
	for(int i = 1; i <= tot; i ++) {
		vector<int> num(N);
		for(int j = i; j <= tot; j ++) {
			f[i][j] = f[i][j - 1];
			g[i][j] = g[i][j - 1];
			for(int k = L[j]; k <= R[j]; k ++) {
				num[rk[k]] ++;
				if(num[rk[k]] > f[i][j]) {
					f[i][j] = num[rk[k]];
					g[i][j] = rk[k];
				}
				else if(num[rk[k]] == f[i][j]) {
					g[i][j] = min(g[i][j], rk[k]);
				}
			}
		}
	}
}

void solve()
{
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		kth[i] = a[i];
	}
	sort(kth.begin() + 1, kth.end());
	kth.erase(unique(kth.begin() + 1, kth.end()), kth.end());
	int k = kth.size() - 1;

	for(int i = 1; i <= n; i ++) {
		rk[i] = krank(a[i]);
	}

	for(int i = 1; i <= n; i ++) {
		pos[i] = bk[rk[i]].size();
		bk[rk[i]].emplace_back(i);
	}
	build(n);

	int ls = 0;
	while(q --) {
		int l, r;
		cin >> l >> r;
		l = (l + ls - 1) % n + 1;
		r = (r + ls - 1) % n + 1;
		if(l > r) swap(l, r);
		ls = query(l, r);
		cout << ls << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	// cin >> t;
	t = 1;
	while(t --)
	{
		solve();
	}
	return 0;
}