#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

struct DSU {
    vector<int> p, siz;
    vector<i64> d;

    DSU(int n = 0) {
        init(n);
    }

    void init(int n) {
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
        siz.assign(n + 1, 0);
        d.assign(n + 1, 0);
    }

    int find(int x) {
        if(x != p[x]) {
            int root = find(p[x]);
            d[x] += d[p[x]];
            p[x] = root;
        }
        return p[x];
    }

    bool merge(int x, int y, i64 k) {
        // 需要注意，带权并查集更新根节点之间距离是需要用到原来的子节点的
        int px = find(x);
        int py = find(y);
        if(px == py) {
            return false;
        }
        p[py] = px;
        // dy到dx的距离为 x到dx的距离 + (y到x的距离 - y到dy的距离)，可以画图更直观地理解
        d[py] = d[x] + k - d[y];
        siz[x] += siz[y];
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    i64 get(int x, int y) {
        // 需要注意，这里理应执行find更新距离的，不过在这之前判断相等的same函数已经执行过了
        // find(x), find(y);
        return d[y] - d[x];
    }
};

const i64 inf = 1e18;
const int mod = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;
    DSU dsu(n + 1);
    while(q --) {
        int op;
        cin >> op;
        if(op == 1) {
            int x, y;
            i64 k;
            cin >> x >> y >> k;
            if(dsu.merge(x, y, k) || dsu.get(x, y) == k) {
                cout << "OK" << '\n';
            } else {
                cout << "CONTRADICTION" << '\n';
            }
        } else if(op == 2) {
            int x;
            i64 k;
            cin >> x >> k;
            if(dsu.merge(x, n + 1, k) || dsu.get(x, n + 1) == k) {
                cout << "OK" << '\n';
            } else {
                cout << "CONTRADICTION" << '\n';
            }
        } else {
            int x, y;
            cin >> x >> y;
            if(dsu.same(x, y)) {
                cout << dsu.get(x, y) << '\n';
            } else {
                cout << "UNKNOWN" << '\n';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}