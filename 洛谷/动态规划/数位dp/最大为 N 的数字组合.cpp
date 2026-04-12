#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/description/

const int inf = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n;
    cin >> n;

    string num = to_string(n);
    int m = num.size();

    vector<int> f(m, -1);
    auto dfs = [&](auto &&self, int u, bool limit, bool zero) -> int {
        if(u == m) {
            return !zero;
        }
        if(!limit && !zero && f[u] != -1) {
            return f[u];
        }
        
        int res = 0;
        if(zero) {
            res += self(self, u + 1, false, zero);
        }

        int up = limit ? num[u] - '0' : 9;
        for(auto c : s) {
            int ch = c - '0';
            if(ch > up) {
                break;
            }
            res += self(self, u + 1, limit && ch == up, false);
        }

        if(!limit && !zero) {
            f[u] = res;
        }
        return res;
    };

    cout << dfs(dfs, 0, 1, 1);
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
