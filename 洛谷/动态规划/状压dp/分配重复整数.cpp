#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/distribute-repeating-integers/description/

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    vector<int> cnt(1);
    int idx = 0;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        if(!mp.count(x)) {
            mp[x] = ++ idx;
            cnt.emplace_back(0);
        }
        x = mp[x];
        cnt[x] ++;
    }

    sort(cnt.begin() + 1, cnt.end(), greater());
    int m;
    cin >> m;
    vector<int> v(m);
    for(int i = 0; i < m; i ++) {
        cin >> v[i];
    }

    n = min(idx, m);
    vector f(n + 1, vector(1 << m, 0));
    f[0][0] = 1;

    vector<int> sum(1 << m);
    for(int i = 0; i < m; i ++) {
        int x = 1 << i;
        for(int mask = 0; mask < x; mask ++) {
            sum[x | mask] = sum[mask] + v[i];
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int mask = 0; mask < (1 << m); mask ++) {
            for(int sub = mask; sub > 0; sub = ((sub - 1) & mask)) {
                int x = (mask ^ sub);
                if(cnt[i] >= sum[x]) {
                    f[i][mask] |= f[i - 1][sub];
                }
            }

            if(cnt[i] >= sum[mask]) {
                f[i][mask] |= f[i - 1][0];
            }
        }
    }

    cout << f[n][(1 << m) - 1] << '\n';
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
