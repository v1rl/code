#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

template <typename Info>
struct SegmentTree
{
    int n;
    vector<Info> info;

    SegmentTree(int n_) : n(n_), info(4 * n + 1) {};
    SegmentTree(vector<Info> a) : SegmentTree(a.size() - 1)
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

    void modify(int p, int l, int r, int x, const int &v)
    {
        if(l == r)
        {
            info[p].apply(v);
            return;
        }
        int mid = l + r >> 1;
        if(x <= mid) modify(p << 1, l, mid, x, v);
        else modify(p << 1 | 1, mid + 1, r, x, v);
        pushup(p);
    }

    void modify(int x, const int &v)
    {
        modify(1, 1, n, x, v);
    }

    Info query(int p, int l, int r, int x, int y)
    {
        if(y < l || x > r) return Info();
        if(x <= l && r <= y) return info[p];
        int mid = l + r >> 1;
        return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid + 1, r, x, y);
    }

    Info query(int x, int y)
    {
        return query(1, 1, n, x, y);
    }
};

struct Info
{
    int sum = 0;
    void apply(const int &v)
    {
        sum += v;
    }
};
Info operator+(Info a, Info b)
{
    Info c;
    c.sum = a.sum + b.sum;
    return c;
}

void solve() {
    int n, m;
    cin >> n >> m;

    string ans(n * 2, ')');
    SegmentTree<Info> tr(n * 2);

    int res = n;
    vector<array<int, 2>> range;
    range.reserve(m);
    while(m --) {
        int l, r;
        cin >> l >> r;
        range.push_back({l, r});
    }
    sort(range.begin(), range.end(), greater());

    for(auto [l, r] : range) {
        if(tr.query(l, r).sum > 0) {
            continue;
        } else {
            if(res == 0) {
                cout << -1 << '\n';
                return;
            }
            ans[l - 1] = '(';
            res --;
            tr.modify(l, 1);
        }
    }

    for(int i = 0; i < 2 * n; i ++) {
        if(ans[i] != '(' && res > 0) {
            ans[i] = '(';
            res --;
        }
    }

    int t = 0;
    for(int i = 0; i < 2 * n; i ++) {
        if(ans[i] == '(') {
            t ++;
        } else {
            t --;
        }
        if(t < 0) {
            cout << -1 << '\n';
            return;
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
}