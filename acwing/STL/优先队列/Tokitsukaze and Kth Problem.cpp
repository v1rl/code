#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://ac.nowcoder.com/acm/contest/95336/G

template<class Info>
struct PresidentTree
{
    int n;
    int idx = 0;
    vector<Info> info;
    PresidentTree(int n_) : n(n_), info(n * (__lg(n) + 2) + 1) {};
    
    void modify(int p, int &q, int l, int r, const int &v)
    {
        q = ++ idx;
        info[q] = info[p];
        info[q].act ++;
        if(l == r) return;
        int mid = l + r >> 1;
        if(v <= mid) modify(info[p].l, info[q].l, l, mid, v);
        else modify(info[p].r, info[q].r, mid + 1, r, v);
    }

    void modify(int p, int &q, const int &v)
    {
        modify(p, q, 1, n, v);
    }

    int kth(int p, int q, int l, int r, int k)
    {
        if(l == r) return l;
        int mid = l + r >> 1;
        int sum = info[info[q].l].act - info[info[p].l].act;
        if(k <= sum) return kth(info[p].l, info[q].l, l, mid, k);
        else return kth(info[p].r, info[q].r, mid + 1, r, k - sum);
    }

    int kth(int p, int q, int k)
    {
        return kth(p, q, 1, n, k);
    }

    int query(int p, int q, int l, int r, int x, int y)
    {
        if(r < x || l > y) return 0;
        if(x <= l && y >= r) return info[q].act - info[p].act;
        int mid = l + r >> 1;
        return query(info[p].l, info[q].l, l, mid, x, y) + query(info[p].r, info[q].r, mid + 1, r, x, y);
    }

    int query(int p, int q, int x, int y)
    {
        return query(p, q, 1, n, x, y);
    }
};

struct Info
{
    int l, r;
    int act = 0;
};

struct Node
{
	int val;
	int id;
	int l, r;

	bool operator < (const Node &W) const
	{
		return val < W.val;
	}
};

void solve()
{
	int n, mod, k;
	cin >> n >> mod >> k;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		a[i] %= mod;
	}

	vector<int> kth = a;
	sort(kth.begin() + 1, kth.end());
	kth.erase(unique(kth.begin() + 1, kth.end()), kth.end());
	auto rk = [&](int x)
	{
		return lower_bound(kth.begin() + 1, kth.end(), x) - kth.begin();
	};

	PresidentTree<Info> tr(n);
	vector<int> root(n + 1);
	for(int i = 1; i <= n; i ++)
		tr.modify(root[i - 1], root[i], rk(a[i]));

	vector<array<int, 2>> range(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		int l, r;
		cin >> l >> r;
		range[i] = {l, r};
	}

	priority_queue<Node, vector<Node>> heap;
	for(int i = 1; i <= n; i ++)
	{
		auto [ql, qr] = range[i];
		int l = 1, r = qr - ql + 1;
		while(l < r)
		{
			int mid = l + r >> 1;
			if(a[i] + kth[tr.kth(root[ql - 1], root[qr], mid)] >= mod) r = mid;
			else l = mid + 1;
		}
		if(a[i] + kth[tr.kth(root[ql - 1], root[qr], l)] >= mod) l --;
		if(l != 0) 
			heap.push({a[i] + kth[tr.kth(root[ql - 1], root[qr], l)], i, 1, l});
		if(l != qr - ql + 1) 
			heap.push({(a[i] + kth[tr.kth(root[ql - 1], root[qr], qr - ql + 1)]) % mod, i, l + 1, qr - ql + 1});
	}

	vector<int> res;
	res.reserve(k);
	while(heap.size() && res.size() < k)
	{
		auto [val, id, l, r] = heap.top();
		heap.pop();

		res.emplace_back(val);
		if(r - 1 >= l)
			heap.push({(a[id] + kth[tr.kth(root[range[id][0] - 1], root[range[id][1]], r - 1)]) % mod, id, l, r - 1});
	}

	while(res.size() < k) res.emplace_back(-1);
	for(auto x : res)
		cout << x << ' ';
	cout << '\n';
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