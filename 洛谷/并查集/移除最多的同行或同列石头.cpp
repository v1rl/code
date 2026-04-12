#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/most-stones-removed-with-same-row-or-column/description/

struct DSU {
    vector<int> p, siz;

    DSU(int n) {
        init(n);
    }

    void init(int n) {
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
        siz.assign(n + 1, 1);
    }

    int find(int x) {
        if(x != p[x]) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) {
            return false;
        }
        p[y] = x;
        siz[x] += siz[y];
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return siz[x];
    }
};

void solve() {
    vector<vector<int>> row(10001), col(10001);
    int n;
    cin >> n;
    DSU dsu(n);
    for(int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        row[x].emplace_back(i);
        col[y].emplace_back(i);
    }

    for(int i = 0; i <= 10000; i ++) {
        if(!row[i].empty()) {
            int fst = row[i][0];
            for(int j = 1; j < row[i].size(); j ++) {
                dsu.merge(fst, row[i][j]);
            }
        }
        if(!col[i].empty()) {
            int fst = col[i][0];
            for(int j = 1; j < col[i].size(); j ++) {
                dsu.merge(fst, col[i][j]);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i ++) {
        if(dsu.find(i) == i) {
            ans ++;
        }
    }

    cout << n - ans << '\n';
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
