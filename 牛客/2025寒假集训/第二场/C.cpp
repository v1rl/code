#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

struct DSU {
    vector<int> p, siz;

    DSU(int n = 0) {
        init(n);
    }

    void init(int n) {
        p.resize(n + 1); 
        iota(p.begin(), p.end(), 0);
        siz.assign(n + 1, 1);
    }

    int find(int x) {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        p[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};

const int inf = 1e6 + 2;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n + 1), y(n + 1);
    vector<int> kth {0, inf};
    for(int i = 1; i <= n; i ++) {
        cin >> x[i] >> y[i];
        kth.emplace_back(x[i]);
        kth.emplace_back(x[i] + 1);
    }

    sort(kth.begin(), kth.end());
    kth.erase(unique(kth.begin(), kth.end()), kth.end());

    int M = kth.size();

    vector<vector<int>> vec(M);
    for(int i = 1; i <= n; i ++) {
        x[i] = lower_bound(kth.begin(), kth.end(), x[i]) - kth.begin();
        vec[x[i]].emplace_back(y[i]);
    }

    vector<vector<array<int, 3>>> seg(M);
    int cnt = 0;
    for(int i = 0; i < M; i ++) {
        int lst = 0;
        vec[i].emplace_back(inf);
        sort(vec[i].begin(), vec[i].end());
        for(auto y : vec[i]) {
            if(y > lst) {
                seg[i].push_back({lst, y - 1, ++ cnt});
            }
            lst = y + 1;
        }
    }


    DSU dsu(cnt);
    for(int i = 1; i < M; i ++) {
        auto &a = seg[i - 1], &b = seg[i];
        int x = 0, y = 0;
        while(x < a.size() && y < b.size()) {
            if(a[x][1] < b[y][1]) {
                if(a[x][1] >= b[y][0]) {
                    dsu.merge(a[x][2], b[y][2]);
                }
                x ++;
            } else {
                if(b[y][1] >= a[x][0]) {
                    dsu.merge(a[x][2], b[y][2]);
                }
                y ++;
            }
        }
    }

    while(m --) {
        int x, y;
        cin >> x >> y;

        x = upper_bound(kth.begin(), kth.end(), x) - kth.begin() - 1;
        y = upper_bound(seg[x].begin(), seg[x].end(), array{y, inf, inf}) - seg[x].begin() - 1;
        if(dsu.same(seg[x][y][2], 1)) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}