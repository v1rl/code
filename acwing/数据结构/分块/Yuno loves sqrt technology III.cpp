#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 5e5 + 10, M = 1e3 + 10;
int a[N], b[N], bel[N];
int L[M], R[M], add[M];
int len, tot;
vector<vector<int>> bs(N);
int pos[N];
int f[M][M];

// https://www.luogu.com.cn/problem/P5048
// 借助桶来判断相隔 x 个的相等数的存在性和距离

void build(int n)
{
	int len = sqrt(n);
	int tot = (n + len - 1) / len;
	for(int i = 1; i <= n; i ++)
	{
		bel[i] = (i - 1) / len + 1;
	}
	for(int i = 1; i <= tot; i ++)
	{
		L[i] = (i - 1) * len + 1;
		R[i] = min(n, i * len);
	}

	for(int i = 1; i <= tot; i ++)
	{
		vector<int> num(N);
		for(int j = i; j <= tot; j ++)
		{
			f[i][j] = f[i][j - 1];
			for(int k = L[j]; k <= R[j]; k ++)
			{
				f[i][j] = max(f[i][j], ++ num[a[k]]);
			}
		}
	}
}

int query(int l, int r)
{
	int x = bel[l], y = bel[r];
	if(x == y)
	{
		unordered_map<int, int> mp;
		for(int i = l; i <= r; i ++)
		{
			mp[a[i]] ++;
		}
		int ans = 0;
		for(auto [_, t] : mp)
			ans = max(ans, t);
		return ans;
	}
	int ans = f[x + 1][y - 1];
	for(int i = l; i <= R[x]; i ++)
	{
		while(pos[i] + ans < bs[a[i]].size() && bs[a[i]][pos[i] + ans] <= r) 
			ans ++;
	}
	for(int i = L[y]; i <= r; i ++)
	{
		while(pos[i] - ans >= 0 && bs[a[i]][pos[i] - ans] >= l)
			ans ++;
	}
	return ans;
}

void solve()
{
	int n, q;
	cin >> n >> q;
	int ls = 0;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		pos[i] = bs[a[i]].size();
		bs[a[i]].emplace_back(i);
	}
	build(n);
	while(q --)
	{
		int l, r;
		cin >> l >> r;
		l ^= ls, r ^= ls;
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