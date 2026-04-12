#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://www.luogu.com.cn/problem/P3413

const int mod = 1e9 + 7;

void solve() {
    string num1, num2;
    cin >> num1 >> num2;

    auto calc = [&](string num) {
        i64 ans = 0;
        for(int i = 0; i < num.size(); i ++) {
            i64 ch = num[i] - '0';
            ans = (ans * 10 + ch) % mod;
        }

        vector f(num.size(), vector(10, vector(10, -1)));
        auto dfs = [&](auto self, int u, int lst1, int lst2, bool limit, bool zero) ->int {
            if(u == num.size()) {
                return 1;
            }
            if(!zero && !limit && lst2 != -1 && f[u][lst1][lst2] != -1) {
                return f[u][lst1][lst2];
            }

            int res = 0;
            int up = limit ? num[u] - '0' : 9;
            int stt = 0;

            if(zero) {
                res = (res + self(self, u + 1, -1, -1, false, zero)) % mod;
                stt ++;
            }

            for(int i = stt; i <= up; i ++) {
                if(i == lst1 || i == lst2) {
                    continue;
                }
                res = (res + self(self, u + 1, i, lst1, limit && i == up, false)) % mod;
            }

            if(!zero && !limit && lst2 != -1) {
                return f[u][lst1][lst2] = res;
            }
            return res;
        };

        return (ans - dfs(dfs, 0, -1, -1, true, true) + mod) % mod;
    };

    auto check = [&](string num) {
        // 注意开头两个字符的特判
        if(num.size() > 1 && num[0] == num[1]) {
            return true;
        }

        for(int i = 2; i < num.size(); i ++) {
            if((num[i] == num[i - 1] || num[i] == num[i - 2])) {
                return true;
            }
        }
        return false;
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
