#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

template<class Info>
struct Segmentree
{
	int n;
	vector<Info> info;
	int idx = 0;

	Segmentree(int n_) : n(n_), info(n * 2 * (__lg(n) + 2)) {};

	void insert(int &p, int l, int r, int x)
	{
		p = ++ idx;
		info[p].sum ++;
		if(l == r) return;
		int mid = l + r >> 1;
		if(x <= mid) insert(info[p].l, l, mid, x);
		else insert(info[p].r, mid + 1, r, x);
	}

	void insert(int &p, int x)
	{
		insert(p, 1, n, x);
	}

	void merge(int &z, int p, int q, int l, int r)
	{
		if(!p && !q) return;
		if(!p || !q)
		{
			z = p + q;
			return;
		}
		z = ++ idx;
		info[z].sum = info[p].sum + info[q].sum;
		int mid = l + r >> 1;
		merge(info[z].l, info[p].l, info[q].l, l, mid);
		merge(info[z].r, info[p].r, info[q].r, mid + 1, r);
	}

	void merge(int &z, int p, int q)
	{
		merge(z, p, q, 1, n); 
	}

	int query(int p, int l, int r, int k)
	{
		if(k > info[p].sum) return -1;
		if(l == r) return l;
		int mid = l + r >> 1;
		if(k <= info[info[p].l].sum) return query(info[p].l, l, mid, k);
		else return query(info[p].r, mid + 1, r, k - info[info[p].l].sum);
	}

	int query(int p, int k)
	{
		return query(p, 1, n, k);
	}
};

struct Info
{
	int l, r;
	int sum;
};

int p[100010];

int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   	int n, m;
   	cin >> n >> m;
   	vector<int> ans(n + 1);
   	vector<int> root(n + 1);
   	
   	for(int i = 1; i <= n; i ++) p[i] = i;
   	Segmentree<Info> tr(n);

   	for(int i = 1; i <= n; i ++)
   	{
   		int x;
   		cin >> x;
   		ans[x] = i;
   		tr.insert(root[i], x);
   	}
   	for(int i = 1; i <= m; i ++)
   	{
   		int x, y;
   		cin >> x >> y;
   		x = find(x), y = find(y);
   		if(x == y) continue;
   		int z = 0;
   		tr.merge(z, root[x], root[y]);
   		p[y] = x;
   		root[x] = z;
   	}

   	int q;
   	cin >> q;
   	while(q --)
   	{
   		char op;
   		cin >> op;
   		int x, y;
   		cin >> x >> y;
   		if(op == 'Q')
   		{
   			x = find(x);
   			int t = tr.query(root[x], y);
   			cout << (t == -1 ? t : ans[t]) << '\n';
   		}
   		else
   		{
   			x = find(x), y = find(y);
   			if(x == y) continue;
   			int z = 0;
   			tr.merge(z, root[x], root[y]);
   			p[y] = x;
   			root[x] = z;
   		}
   	}
    return 0;
}