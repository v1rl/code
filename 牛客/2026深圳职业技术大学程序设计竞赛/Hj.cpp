#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

const int mod = 998244353;

vector<int> fact, infact;
void init(int n) {
    fact.resize(n + 1);
    infact.resize(n + 1);
    fact[0] = infact[0] = fact[1] = infact[1] = 1;
    for(int i = 2; i <= n; i ++) {
        fact[i] = 1ll * fact[i - 1] * i % mod;
        infact[i] = 1ll * (mod - mod / i) * infact[mod % i] % mod;
    }
    for(int i = 2; i <= n; i ++) {
        infact[i] = 1ll * infact[i] * infact[i - 1] % mod;
    }
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> adj(n + 1);
    vector<int> fa(n + 1);
    int u = 1;
    int idx = 1;
    for(auto c : s) {
        if(c == '(') {
            adj[u].emplace_back(++ idx);
            fa[idx] = u;
            u = idx;
        } else {
            u = fa[u];
        }
    }

    map<vector<int>, int> mp;
    int cur = 0;

    i64 ans = 1;
    auto dfs = [&](auto &&self, int x) -> int {
        vector<int> child;
        map<int, int> cnt;

        for(auto y : adj[x]) {
            int id = self(self, y);
            cnt[id] ++;
            child.emplace_back(id);
        }

        ans = ans * fact[child.size()] % mod;
        for(auto [_, c] : cnt) {
            ans = ans * infact[c] % mod;
        }

        sort(child.begin(), child.end());
        if(!mp.count(child)) {
            mp[child] = ++cur;
        }
        return mp[child];
    };

    dfs(dfs, 1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    init(100000);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
