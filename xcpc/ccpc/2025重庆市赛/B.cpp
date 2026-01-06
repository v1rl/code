#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e18;

struct Node
{
	int l, r;
	i64 cap;
	i64 flow;

	bool operator < (const Node &W) const
	{
		if(r != W.r) return r < W.r;
		return l < W.l;
	}
};


struct DSU
{
    vector<int> p, siz;

    DSU(int n = 0)
    {
        init(n);
    }

    void init(int n)
    {
        p.resize(n + 1); 
        iota(p.begin(), p.end(), 0);
        siz.assign(n + 1, 1);
    }

    int find(int x)
    {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if(x == y) return false;
        p[y] = x;
        siz[x] += siz[y];
        return true;
    }
};

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<Node> a(m + 1);
	for(int i = 1; i <= m; i ++)
	{
		int l, r;
		i64 cap;
		cin >> l >> r >> cap;
		a[i] = {l, r, cap, 0};
	}
	a[0] = {1, 1, inf, inf};
	sort(a.begin() + 1, a.end());

	vector<int> lst(m + 1), ne(m + 1);
	for(int i = 1; i <= m; i ++)
	{
		ne[i] = i + 1;
		lst[i] = i - 1;
	}
	ne[0] = 1;
	ne[m] = -1;

	DSU dsu(m + 1);

	i64 ans = 0;
	for(int i = 1; i <= m; i ++)
	{
		int l = 0, r = i;
		while(l < r)
		{
			int mid = l + r >> 1;
			if(a[mid].r >= a[i].l) r = mid;
			else l = mid + 1; 
		}
		if(l == i) continue;

		int p = dsu.find(l);
		int stt = p == l ? p : ne[p];
		for(int j = stt; j < i && j != -1; j = ne[j])
		{
			i64 t = min(a[i].cap - a[i].flow, a[j].flow);
			a[i].flow += t;
			a[j].flow -= t;

			if(a[j].flow == 0)
			{
				dsu.merge(lst[j], j);
				ne[lst[j]] = ne[j];
				lst[ne[j]] = lst[j];
			}

			if(a[i].flow == a[i].cap) break;
		}
		if(a[i].r == n) 
		{
			ans += a[i].flow;
			a[i].flow = 0;
		}
	}

	cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --)
    {
        solve();
    }
    return 0;
}