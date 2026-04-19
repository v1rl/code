#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;

struct Node {
    int x, y, v, op;
    bool operator < (const Node &ano) const {
        if(v != ano.v) {
            return v < ano.v;
        }
        if(op != ano.op) {
            return op < ano.op;
        }
        if(x != ano.x) {
            return x > ano.x;
        }
        return y > ano.y;
    }
};

int opp(int x) {
    return ((x & 1) ? x + 1 : x - 1);
}

void solve() {
    int n, m, q;
    cin >> m >> n >> q;
    vector z(n * 2 + 1, vector(m + 1, 0));
    vector<array<int, 2>> ans;
    vector<Node> bst(n * 2 + 1);
    for(int i = 1; i <= n * 2; i ++) {
        bst[i] = {i, 1, m, 1};
    }

    auto get = [&]() {
        Node res = {-1, -1, -inf, 0};
        for(int i = 1; i <= n * 2; i ++) {
            res = max(res, bst[i]);
        }
        return res;
    };

    auto update = [&](int i) {
        vector<int> l(m + 1), r(m + 1);
        int lst = -inf;
        for(int j = 1; j <= m; j ++) {
            if(z[i][j]) {
                lst = j;
            }
            l[j] = j - lst;
        }
        lst = inf;
        for(int j = m; j >= 1; j --) {
            if(z[i][j]) {
                lst = j;
            }
            r[j] = lst - j;
        }

        Node res = {-1, -1, -inf, 0};
        for(int j = 1; j <= m; j ++) {
            if(!z[i][j]) {
                int v = min({l[j], r[j], m});
                Node cur = {i, j, v, !z[opp(i)][j]};
                res = max(res, cur);                
            }
        }
        bst[i] = res;
    };

    while(q --) {
        int op, id;
        cin >> op >> id;
        if(op == 1) {
            auto [x, y, _1, _2] = get();
            if(x == -1) {
                ans.push_back({-1, -1});
                continue;
            }
            ans.push_back({x, y});
            z[x][y] = 1;
            update(x), update(opp(x));
        } else {
            auto [x, y] = ans[id - 1];
            z[x][y] = 0;
            update(x), update(opp(x));
        }
    }

    for(auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
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