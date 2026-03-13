#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
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

void solve() {
    int n, m, x, d;
    cin >> n >> m >> x >> d;

    vector<int> h(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> h[i];
    }

    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    sort(p.begin() + 1, p.end(), 
        [&](int x, int y) {
            return h[x] > h[y];
        });

    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    vector<int> H(x + 1);
    for(int i = 1; i <= x; i ++) {
        cin >> H[i];
    }


    DSU dsu(n);

    vector<int> ans(x + 2);
    vector<int> st(n + 1);
    int j = 1;
    for(int i = x; i; i --) {
        ans[i] = ans[i + 1];
        while(j <= n && h[p[j]] > H[i]) {
            int cur = p[j];
            st[cur] = true;

            // 想清楚合并操作本质是什么再来更新计数
            for(auto y : adj[cur]) {
                if(st[y]) {
                    if(dsu.same(cur, y)) {
                        continue;
                    }
                    ans[i] -= (dsu.size(y) >= d);
                    dsu.merge(cur, y);
                }
            }
            ans[i] += dsu.size(cur) >= d;

            j ++;
        }
    }

    for(int i = 1; i <= x; i ++) {
        cout << ans[i] << '\n';
    }
    cout << '\n';
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