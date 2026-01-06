#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e6 + 10;

// https://www.luogu.com.cn/problem/P2163

/*
关键词：边遍历边维护，离线询问，树状数组，离散化

按照x升序遍历每个点所处的位置，然后离散化y
我们可以得到x截至目前，y某一区间上的点的个数cur
通过cur(x2) - cur(x1)便能得到答案
*/

const int inf = 1e9;

template<typename T>
struct Fenwick {
    int n;
    vector<T> a;

    Fenwick(int n_) : n(n_), a(n + 1) {};

    void add(int x, const T &v) {
        for(int i = x; i <= n; i += i & -i)
            a[i] += v;
    }

    T sum(int x) {
        T res{};
        for(int i = x; i; i -= i & -i)
            res += a[i];
        return res;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> points(n);
    vector<int> kth;
    for(int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
        kth.emplace_back(y);
    }
    sort(points.begin(), points.end());

    vector<array<int, 4>> query;
    for(int i = 0; i < m; i ++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        query.push_back({x1 - 1, y1, y2, i});
        query.push_back({x2, y1, y2, i});
        kth.emplace_back(y1);
        kth.emplace_back(y2);
    }

    // 需要注意，询问的y也必须放到离散化数组中
    sort(kth.begin(), kth.end());
    kth.erase(unique(kth.begin(), kth.end()), kth.end());
    auto rank = [&](int x) {
        return lower_bound(kth.begin(), kth.end(), x) - kth.begin();
    };

    vector<int> ans(m, -inf);
    sort(query.begin(), query.end());
    Fenwick<int> tr(kth.size());

    // 需要注意，这里以询问为外层循环，点为内层循环
    // 因为点的处理与否会影响询问结果，但询问结果的处理进度不会影响点，且同一个x上可能存在多个点
    int cnt = 0;
    for(auto [qx, y1, y2, id] : query) {
        while(cnt < points.size() && points[cnt][0] <= qx) {
            auto [x, y] = points[cnt];
            y = rank(y);
            tr.add(y + 1, 1);
            cnt ++;
        }
        y1 = rank(y1), y2 = rank(y2);
        if(ans[id] == -inf) {
            ans[id] = -tr.rangeSum(y1 + 1, y2 + 1);
        } else {
            ans[id] += tr.rangeSum(y1 + 1, y2 + 1);
        }
    }

    for(auto c : ans) {
        cout << c << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}