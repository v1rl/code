#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://www.nowcoder.com/practice/aaefe5896cce4204b276e213e725f3ea

const int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector f(m + 1, vector(n + 1, -1));
    auto dfs = [&](auto &&self, int h, int num) {
        if(num == 0) {
            return 1;
        }
        if(h > m) {
            return 0;
        }
        if(f[h][num] != -1) {
            return f[h][num];
        }
        i64 res = 0;
        for(int i = 0; i <= num - 1; i ++) {
            res += 1ll * self(self, h + 1, i) * self(self, h + 1, num - i - 1); 
            res %= mod;
        }
        return f[h][num] = res;
    };

    cout << dfs(dfs, 1, n) << '\n';
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
