#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones/description/

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> num;
    while(n) {
        num.emplace_back(n % 2);
        n /= 2;
    }
    reverse(num.begin(), num.end());

    vector f(num.size(), vector(2, -1));
    auto dfs = [&](auto &&self, int u, int lst, bool limit) {
        if(u == num.size()) {
            return 1;
        }
        if(!limit && f[u][lst] != -1) {
            return f[u][lst];
        }

        int res = 0;
        int up = limit ? num[u] : 1;
        res += self(self, u + 1, 0, limit && up == 0);
        if(lst != 1 && up == 1) {
            res += self(self, u + 1, 1, limit && up == 1);
        }

        if(!limit) {
            f[u][lst] = res;
        }
        return res;
    };

    cout << dfs(dfs, 0, 0, true) << '\n';
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
