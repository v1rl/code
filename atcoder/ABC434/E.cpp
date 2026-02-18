#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
题意可转化为：一条边只能选一个点的情况下，最多可以选多少个点
显然，如果这样的图是树，一定可以选n-1个点
注意到：如果这样的图是常规图，我们可以找到其中的最小生成树，这样一定可以选n-1个点，多余出来的边则可以补足剩下的那个点，则一定可以全选
于是，只需要判断最终有多少树多少常规图即可
判断图是否是树，可以通过dfs遍历所有边看同一个点是否会被访问两次
*/

void solve() {
    int n;
    cin >> n;
    map<int, vector<array<int, 2>>> adj;

    for(int i = 0; i < n; i ++) {
        int x, p;
        cin >> x >> p;
        adj[x - p].push_back({x + p, i});
        adj[x + p].push_back({x - p, i});
    }

    set<int> S;
    // 需要注意，要遍历所有边，所以存来源边而不是来源点
    auto dfs = [&](auto &&self, int x, int ep, int &num, bool &f) -> void {
        for(auto [y, eid] : adj[x]) {
            if(eid == ep) {
                continue;
            }
            if(!S.count(y)) {
                num ++;
                S.insert(y);
                self(self, y, eid, num, f);
            } else {
                f = false;
            }
        }
    };

    int ans = 0;
    for(auto [x, _] : adj) {
        if(!S.count(x)) {
            S.insert(x);
            int num = 1;
            bool f = true;
            dfs(dfs, x, -1, num, f);
            ans += (f ? num - 1 : num);
        }
    }

    cout << ans << '\n';
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
