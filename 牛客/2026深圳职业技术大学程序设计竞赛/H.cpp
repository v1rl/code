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
    vector<int> stk;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '(') {
            stk.emplace_back(0);
        } else {
            if(stk.back() == 0) {
                stk.pop_back();
                stk.push_back(2);
            } else if(stk[stk.size() - 2] == 0) {
                int t = stk.back();
                stk.pop_back();
                stk.pop_back();
                stk.push_back(t + 1);
            } else {
                stk.push_back(1);
            }
        }
    }

    vector<vector<int>> adj(n + 1);
    vector<int> val(n + 1);
    vector<u64> hash(n + 1);
    int idx = 1;
    int u = 0;
    auto build = [&](auto &&self, int root) -> void {
        while(u < stk.size()) {
            if(stk[u] == 0) {
                adj[root].push_back(++ idx);
                val[idx] = stk[u];
                u ++;
                self(self, idx);
            } else if(stk[u] == 1) {
                u ++;
                break;
            } else {
                adj[root].push_back(++ idx);
                val[idx] = stk[u];
                u ++;                
            }
        }
    };

    build(build, 1);

    mt19937_64 rng(114614);
    map<u64, u64> mp;

    i64 ans = 1;
    auto dfs = [&](auto &&self, int x) -> void {
        if(!mp.count(val[x])) {
            mp[val[x]] = rng();
        }
        u64 sum = mp[val[x]];

        map<u64, int> cnt;
        for(auto y : adj[x]) {
            self(self, y);
            cnt[hash[y]] ++;
            sum += hash[y];
        }

        int total = 0;
        for(auto [_, t] : cnt) {
            ans = ans * infact[t] % mod;
            total += t;
        }
        ans = ans * fact[total] % mod;

        if(!mp.count(sum)) {
            mp[sum] = rng();
        }
        hash[x] = mp[sum];
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
