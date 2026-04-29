#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    i64 n, m, A, B;
    cin >> n >> m >> A >> B;
    vector<vector<i64>> pos(1 << m);
    vector<vector<i64>> pre(1 << m);

    for(int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        int st = 0;
        for(int j = 0; j < m; j ++) {
            if(s[j] == '1') {
                st ^= (1 << j);
            }
        }

        pos[st].emplace_back(i + 1);
    }

    for(int mask = 0; mask < (1 << m); mask ++) {
        pre[mask].assign(pos[mask].size() + 1, 0);
        for(int j = 1; j < pre[mask].size(); j ++) {
            pre[mask][j] += pre[mask][j - 1] + pos[mask][j - 1];
        }
    }


    i64 ans = -9e18;
    for(int mask = 0; mask < (1 << m); mask ++) {
        i64 res = 0;
        for(int st = 0; st < (1 << m); st ++) {
            if(pos[st].empty()) {
                continue;
            }
            i64 cur = st ^ mask;
            i64 cnt = __builtin_popcount(cur);

            i64 W = 0;
            for(int j = 0; j < m; j ++) {
                if(cur >> j & 1) {
                    W += j + 1;
                }
            }

            i64 C1 = 1ll * (2 * cnt - m) * A;
            i64 C2 = 1ll * ((m + 1) * m / 2 - 2 * W) * B;
            int split = 0;
            bool rev = 0;
            if(C1 > 0) {
                int l = 0, r = pos[st].size();
                while(l < r) {
                    int mid = l + r >> 1;
                    if(pos[st][mid] * C1 > C2) {
                        r = mid;
                    } else {
                        l = mid + 1;
                    }
                }
                split = l;
                rev = true;
            } else if(C1 < 0) {
                int l = -1, r = pos[st].size() - 1;
                while(l < r) {
                    int mid = l + r + 1 >> 1;
                    if(pos[st][mid] * C1 > C2) {
                        l = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                split = l + 1;
                rev = false;
            } else {
                split = 0;
                if(C2 < 0) {
                    rev = true;    
                } else {
                    rev = false;
                }
            }

            i64 numl = split;
            i64 numr = pos[st].size() - split;
            i64 suml = pre[st][split];
            i64 sumr = pre[st].back() - suml;

            if(rev) {
                res += (m * (m + 1) / 2 - W) * B * numl + suml * (m - cnt) * A;
                res += numr * W * B + sumr * cnt * A;
            } else {
                res += (m * (m + 1) / 2 - W) * B * numr + sumr * (m - cnt) * A;
                res += numl * W * B + suml * cnt * A;
            }
        }

        ans = max(ans, res);
    }
    cout << ans << '\n';
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
