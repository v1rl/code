#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/numbers-with-repeated-digits/description/

const int mod = 1e9 + 7;

void solve() {
    string num;
    cin >> num;
    int n = num.size();
    vector f(n, vector(1 << 10, -1));

    auto dfs = [&](auto &&self, int u, int s, bool limit, bool zero) ->int {
        if(u == n) {
            return !zero;
        }
        if(!limit && !zero && f[u][s] != -1) {
            return f[u][s];
        }

        int res = 0;
        int up = limit ? num[u] - '0' : 9;
        int stt = 0;

        if(zero) {
            res += self(self, u + 1, s, false, zero);
            stt = 1;
        }

        for(int i = stt; i <= up; i ++) {
            if(~s >> i & 1) {
                res += self(self, u + 1, s ^ (1 << i), limit && i == up, false);
            }
        }

        if(!limit) {
            f[u][s] = res;
        }
        return res;
    };

    cout << stoi(num) - dfs(dfs, 0, 0, true, true) << '\n';
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
