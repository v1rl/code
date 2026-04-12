#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/count-of-integers/description/

const int mod = 1e9 + 7;

void solve() {
    string num1, num2;
    cin >> num1 >> num2;

    int l, r;
    cin >> l >> r;

    auto calc = [&](string num) {
        vector f(23, vector(r + 1, -1));
        auto dfs = [&](auto &&self, int u, int sum, bool limit) -> int{
            if(u == num.size()) {
                return (sum >= l && sum <= r);
            }
            if(sum > r) {
                return 0;
            }
            if(!limit && f[u][sum] != -1) {
                return f[u][sum];
            }

            int res = 0;
            int up = limit ? num[u] - '0' : 9;
            for(int i = 0; i <= up; i ++) {
                res = (res + self(self, u + 1, sum + i, limit && i == up)) % mod;
            }
            if(!limit) {
                f[u][sum] = res;
            }
            return res;
        };

        return dfs(dfs, 0, 0, true);
    };

    auto check = [&](string s) {
        int res = 0;
        for(auto c : s) {
            res += c - '0';
        }
        return (res >= l && res <= r);
    };

    cout << (calc(num2) - calc(num1) + check(num1) + mod) % mod << '\n';
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
