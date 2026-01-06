#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using i64 = long long;
using i128 = __int128;
const int inf = 1e9 + 7;
const int mod = pow(2, 30);

// https://acm.hdu.edu.cn/showproblem.php?pid=6356

template<class Info>
struct Segmentree
{
	int n;
	vector<Info> info;

	Segmentree(int n_) : n(n_), info(4 * n + 1) {};

	void pushup(int p)
	{
		info[p] = info[p << 1] + info[p << 1 | 1];
	}

	void modify(int p, int l, int r, int x, int y, const int v)
	{
		if(v < info[p].val) return;
		if(y < l || x > r) return;
		if(x <= l && y >= r)
		{
			info[p].val = max(info[p].val, v);
			return;
		}
		int mid = l + r >> 1;
		modify(p << 1, l, mid, x, y, v);
		modify(p << 1 | 1, mid + 1, r, x, y, v);
	}

	void modify(int x, int y, const int &v)
	{
		modify(1, 1, n, x, y, v);
	}

	void update(int p, int l, int r, int val)
	{
		val = max(val, info[p].val);
		if(l == r)
		{
			info[p].sum = 1ll * l * val;
			return;
		}
		int mid = l + r >> 1;
		update(p << 1, l, mid, val);
		update(p << 1 | 1, mid + 1, r, val);
		pushup(p);
	}

	i64 query()
	{
		update(1, 1, n, 0);
		return info[1].sum;
	}
};

struct Info
{
	i64 sum = 0;
	int val = 0;
};

Info operator+(Info a, Info b)
{
	Info c;
	c.sum = a.sum ^ b.sum;
	return c;
};

u32 x, y, z;
u32 get()
{
    x = x ^ (x << 11);x = x ^ (x >> 4);
    x = x ^ (x << 5);x = x ^ (x >> 14);
    u32 w = x ^ (y ^ z);
    x = y;y = z;z = w;
    return z;
}


void solve()
{
	u32 n, m;
	cin >> n >> m >> x >> y >> z;
	vector<u32> f(m * 3 + 1);
	for(int i = 1; i <= m * 3; i ++)
		f[i] = get();

	Segmentree<Info> tr(n);
	for(int i = 1; i <= m; i ++)
	{
		int l = min(f[3 * i - 2] % n + 1, f[3 * i - 1] % n + 1);
		int r = max(f[3 * i - 2] % n + 1, f[3 * i - 1] % n + 1);
		int v = f[3 * i] % mod;
		tr.modify(l, r, v);
	}

	cout << tr.query() << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    // t = 1;
    while(t --)
    {
        solve();
    }
    return 0;
}