#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int floor(int n, int m)
{
	if(n >= 0) return n / m;
	return (n - m + 1) / m;
}


template<class Info, class Tag>
struct LazySegmentTree
{
    int n;
    vector<Info> info;
    vector<Tag> tag;

    LazySegmentTree(int n_) : n(n_), info(4 * n + 1), tag(4 * n + 1) {};
    LazySegmentTree(vector<Info> a) : LazySegmentTree(a.size() - 1)
    {
        function<void(int, int, int)> build = [&](int p, int l, int r)
        {
            if(l == r)
            {
                info[p] = a[l];
                return;
            }
            int mid = l + r >> 1;
            build(p << 1, l, mid);
            build(p << 1 | 1, mid + 1, r);
            pushup(p);
        };
        build(1, 1, n);
    }

    void pushup(int p)
    {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }

    void apply(int p, const Tag &t)
    {
        info[p].apply(t);
        tag[p].apply(t);
    }

    void pushdown(int p)
    {
        apply(p << 1, tag[p]);
        apply(p << 1 | 1, tag[p]);
        tag[p] = Tag();
    }

    void rangeApply1(int p, int l, int r, int x, int y, const Tag &t)
    {
        if(r < x || l > y) return;
        if(x <= l && r <= y)
        {
            apply(p, t);
            return;
        }
        pushdown(p);
        int mid = l + r >> 1;
        rangeApply1(p << 1, l, mid, x, y, t);
        rangeApply1(p << 1 | 1, mid + 1, r, x, y, t);
        pushup(p);
    }

    void rangeApply1(int x, int y, const Tag &t)
    {
        rangeApply1(1, 1, n, x, y, t);
    }

    void rangeApply2(int p, int l, int r, int x, int y, const int &d)
    {
        if(r < x || l > y) return;
        if(x <= l && r <= y)
        {
            int mx = info[p].max, mn = info[p].min;
            int mxd = mx - floor(mx, d), mnd = mn - floor(mn, d);
            if(mxd == mnd)
            {
            	apply(p, {-mxd});
            	return;
            }
        }
        if(l == r)
        {
        	info[p].apply(d);
        	return;
        }
        pushdown(p);
        int mid = l + r >> 1;
        rangeApply2(p << 1, l, mid, x, y, d);
        rangeApply2(p << 1 | 1, mid + 1, r, x, y, d);
        pushup(p);
    }

    void rangeApply2(int l, int r, const int &d)
    {
		rangeApply2(1, 1, n, l, r, d);
    }

    Info query(int p, int l, int r, int x, int y)
    {
        if(r < x || l > y) return Info();
        if(x <= l && r <= y) return info[p];
        pushdown(p);
        int mid = l + r >> 1;
        return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid + 1, r, x, y);
    }

    Info query(int x, int y)
    {
        return query(1, 1, n, x, y);
    }
};
constexpr int inf = 2e9;

struct Tag
{
    i64 add = 0;

    void apply(const Tag &t)
    {
        add += t.add;
    }
};

struct Info
{
    int min = inf;
    int max = -inf;
    i64 sum = 0;
    int act = 0;

    void apply(const Tag &t)
    {
        min += t.add;
        max += t.add;
        sum += act * t.add;
    }
    void apply(const int &d)
    {
    	min = floor(min, d);
    	max = floor(max, d);
    	sum = floor(sum, d);
    }
};

Info operator+(Info a, Info b)
{
    Info c;
    c.min = min(a.min, b.min);
    c.max = max(a.max, b.max);
    c.sum = a.sum + b.sum;
    c.act = a.act + b.act; 
    return c;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<Info> info(n + 1);
    for(int i = 1; i <= n; i ++)
    {
    	int x;
    	cin >> x;
    	info[i] = {x, x, x, 1};
    }
    LazySegmentTree<Info, Tag> tr(info);
    while(m --)
    {
    	int op;
    	int l, r;
    	cin >> op >> l >> r;
    	l ++, r ++;
    	if(op == 1)
    	{
    		int d;
    		cin >> d;
    		tr.rangeApply1(l, r, {d});
    	}
    	else if(op == 2)
    	{
    		int d;
    		cin >> d;
    		tr.rangeApply2(l, r, d);
    	}
    	else if(op == 3)
    	{
    		cout << tr.query(l, r).min << '\n';
    	}
    	else
    	{
    		cout << tr.query(l, r).sum << '\n';
    	}
    	// for(int i = 1; i <= n; i ++) cout << tr.query(i, i).sum << " \n"[i == n];
    }
    return 0;
}