#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/minimum-number-of-days-to-eat-n-oranges/description/

void solve() {
    int n;
    cin >> n;

    unordered_map<int, int> mp;
    auto dfs = [&](auto &&self, int x) {
        if(x <= 1) {
            return x;
        }
        if(mp.count(x)) {
            return mp[x];
        }
        return mp[x] = min(x % 2 + 1 + self(self, x / 2), x % 3 + 1 + self(self, x / 3));
    };

    cout << dfs(dfs, n) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}