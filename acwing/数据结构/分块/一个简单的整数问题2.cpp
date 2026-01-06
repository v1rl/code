#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 350, M = 1e5 + 10;
i64 sum[N], add[N];
i64 w[M];
int len;

int get(int i)
{
	return (i - 1) / len;
}

void modify(int l, int r, int d)
{
	int x = get(l), y = get(r);
	if(x == y)
	{
		for(int i = l; i <= r; i ++)		//暴力修改w的同时还要修改它所归属的sum
			w[i] += d, sum[x] += d;
	}
	else
	{
		int i = l;
		while(get(i) == x) w[i] += d, sum[x] += d, i ++;		//同理
		int j = r;
		while(get(j) == y) w[j] += d, sum[y] += d, j --;
		for(int k = x + 1; k < y; k ++)
		{
			sum[k] += 1ll * len * d;
			add[k] += d;
		}
	}
}

i64 query(int l, int r)
{
	int x = get(l), y = get(r);
	i64 res = 0;
	if(x == y)
	{
		for(int i = l; i <= r; i ++)		//懒标记是为累加w准备的
			res += w[i] + add[x];
	}
	else
	{
		int i = l;
		while(get(i) == x) res += w[i] + add[x], i ++;
		int j = r;
		while(get(j) == y) res += w[j] + add[y], j --;
		for(int k = x + 1; k < y; k ++)
		{
			res += sum[k];		//sum则直接加
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	len = sqrt(n);
	for(int i = 1; i <= n; i ++)
	{
		cin >> w[i];
		sum[get(i)] += w[i];
	}
	while(m --)
	{
		char op;
		int l, r;
		cin >> op >> l >> r;
		if(op == 'C')
		{
			int d;
			cin >> d;
			modify(l, r, d);
		}
		else
		{
			cout << query(l, r) << '\n';
		}
	}
}