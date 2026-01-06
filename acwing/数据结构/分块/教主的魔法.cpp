#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e6 + 10, M = 1e3 + 10;
int a[N], b[N], bel[N];
int L[M], R[M], add[M];
int len, tot;

// https://www.luogu.com.cn/problem/P2801

void build(int n)
{
	len = sqrt(n);
	tot = (n + len - 1) / len;
	for(int i = 1; i <= n; i ++)
	{
		bel[i] = (i - 1) / len + 1;
	}
	for(int i = 1; i <= tot; i ++)
	{
		L[i] = len * (i - 1) + 1;
		R[i] = min(len * i, n);
		sort(b + L[i], b + R[i] + 1);
	}
}

void reset(int x)
{
	for(int i = L[x]; i <= R[x]; i ++)
		b[i] = a[i];
	int t = R[x] - L[x] + 1;
	// memcpy(b + L[x], a + L[x], t * sizeof(int));
	sort(b + L[x], b + R[x] + 1);
}

void modify(int l, int r, int w)
{
	int x = bel[l], y = bel[r];
	if(x == y)
	{
		for(int i = l; i <= r; i ++)
		{
			a[i] += w;
		}
		reset(x);
		return;
	}
	for(int i = l; i <= R[x]; i ++)
		a[i] += w;
	for(int i = L[y]; i <= r; i ++)
	{
		a[i] += w;
	}
	reset(x), reset(y);
	for(int i = x + 1; i < y; i ++)
		add[i] += w;
}

int query(int l, int r, int k)
{
	int res = 0;
	int x = bel[l], y = bel[r];
	if(x == y)
	{
		for(int i = l; i <= r; i ++)
		{
			if(a[i] + add[x] >= k)
				res ++;
		}
		return res;
	}
	for(int i = l; i <= R[x]; i ++)
		if(a[i] + add[x] >= k)
			res ++;
	for(int i = L[y]; i <= r; i ++)
		if(a[i] + add[y] >= k)
			res ++;
	for(int i = x + 1; i < y; i ++)
	{
		int pos = lower_bound(b + L[i], b + R[i] + 1, k - add[i]) - b;
		res += R[i] - pos + 1;
	}
	return res;
}

void solve()
{
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	build(n);
	while(q --)
	{
		char op;
		cin >> op;
		int l, r;
		cin >> l >> r;
		if(op == 'A')
		{
			int k;
			cin >> k;
			cout << query(l, r, k) << '\n';
		}
		else
		{
			int w;
			cin >> w;
			modify(l, r, w);
		}
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