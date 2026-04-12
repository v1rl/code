#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://www.luogu.com.cn/problem/P2657

const int mod = 1e9 + 7;

void solve() {
    i64 n1, n2;
    cin >> n1 >> n2;
    n1 --;
    string num1 = to_string(n1);
    string num2 = to_string(n2);

    auto calc = [&](string num) {
        vector f(num.size(), vector(10, (i64)-1));
        auto dfs = [&](auto &&self, int u, int lst, bool limit, bool zero) -> i64 {
            if(u == num.size()) {
                return !zero;
            }
            if(!limit && !zero && f[u][lst] != -1) {
                return f[u][lst];
            }

            i64 res = 0;
            int up = limit ? num[u] - '0' : 9;
            for(int i = 0; i <= up; i ++) {
                if(zero || abs(i - lst) >= 2) {
                    res += self(self, u + 1, i, limit && i == up, zero && i == 0);
                }
            }

            if(!limit && !zero) {
                f[u][lst] = res;
            }
            return res;
        };

        return dfs(dfs, 0, 0, true, true);
    };

    cout << calc(num2) - calc(num1) << '\n';
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
