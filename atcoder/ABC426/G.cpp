#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
考虑数据结构维护
线段树的固定区间预处理合并需要处理所有C，时间复杂度在平方级别，显然不可取
注意到：本题只有询问没有修改，单点扩展的复杂度只有O(C)
如果直接离线处理询问，因为询问自带固定的C，时间复杂度只有O(C)
所以，考虑分治通过扩展预处理左右区间，然后合并处理跨区间的询问
复杂度O(C*(NlogN+Q))
*/

void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1), v(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> v[i] >> w[i];
    }

    int q;
    cin >> q;
    vector<array<int, 4>> query(q);
    int m = 500;
    for(int i = 0; i < q; i ++) {
        int l, r, c;
        cin >> l >> r >> c;
        query[i] = {l, r, c, i};
    }

    vector dp(n + 1, vector(m + 1, 0ll));
    vector<i64> ans(q);
    auto cdq = [&](auto &&self, int l, int r, vector<array<int, 4>> &q) {
        if(q.empty()) {
            return;
        }
        if(l == r) {
            for(auto &[_, __, c, id] : q) {
                if(c >= v[l]) {
                    ans[id] = w[l];
                } else {
                    ans[id] = 0;
                }
            }
            return;
        }

        int mid = l + r >> 1;
        vector<array<int, 4>> ql, qr, qm;
        for(auto &[nl, nr, c, id] : q) {
            if(nr <= mid) {
                ql.push_back({nl, nr, c, id});
            } else if(nl > mid) {
                qr.push_back({nl, nr, c, id});
            } else {
                qm.push_back({nl, nr, c, id});
            }
        }

        self(self, l, mid, ql);
        self(self, mid + 1, r, qr);

        if(qm.size()) {
            for(int j = 0; j <= m; j ++) {
                if(j >= v[mid]) {
                    dp[mid][j] = w[mid];
                } else {
                    dp[mid][j] = 0;
                }
            }
            for(int i = mid - 1; i >= l; i --) {
                for(int j = 0; j <= m; j ++) {
                    dp[i][j] = dp[i + 1][j];
                    if(j >= v[i]) {
                        dp[i][j] = max(dp[i][j], dp[i + 1][j - v[i]] + w[i]);
                    }
                }
            }

            for(int j = 0; j <= m; j ++) {
                if(j >= v[mid + 1]) {
                    dp[mid + 1][j] = w[mid + 1];
                } else {
                    dp[mid + 1][j] = 0;
                }
            }
            for(int i = mid + 2; i <= r; i ++) {
                for(int j = 0; j <= m; j ++) {
                    dp[i][j] = dp[i - 1][j];
                    if(j >= v[i]) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
                    }
                }
            }
        }

        for(auto &[nl, nr, c, id] : qm) {
            i64 res = 0;
            for(int i = 0; i <= c; i ++) {
                res = max(res, dp[nl][i] + dp[nr][c - i]);
            }
            ans[id] = res;
        }
    };

    cdq(cdq, 1, n, query);
    for(auto c : ans) {
        cout << c << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(15);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}