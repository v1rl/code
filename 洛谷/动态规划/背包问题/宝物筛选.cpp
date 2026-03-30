#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://www.luogu.com.cn/problem/P1776

/*
*/

const int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    /*
    // 二进制优化
    vector<int> v, w;
    for(int i = 0; i < n; i ++) {
        int cv, cw, cnt;
        cin >> cw >> cv >> cnt;

        int j = 0;
        while(cnt) {
            int x = min(cnt, 1 << j);
            cnt -= x;
            v.emplace_back(cv * x);
            w.emplace_back(cw * x);
            j ++;
        }
    }

    n = v.size();

    vector<int> f(m + 1);
    for(int i = 0; i < n; i ++) {
        for(int j = m; j >= v[i]; j --) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    cout << f[m] << '\n';
    */

    vector<int> v(n), w(n), c(n);
    for(int i = 0; i < n; i ++) {
        cin >> w[i] >> v[i] >> c[i];
    }

    vector<int> dp(m + 1);
    for(int i = 0; i < n; i ++) {
        vector<int> ndp(m + 1);
        for(int k = 0; k < min(m + 1, v[i]); k ++) {
            deque<int> q;
            for(int j = k; j <= m; j += v[i]) {
                if(q.size() && q.front() < j - v[i] * c[i]) {
                    q.pop_front();
                }
                while(q.size() && dp[q.back()] + (j - q.back()) / v[i] * w[i] <= dp[j]) {
                    q.pop_back();
                }
                q.push_back(j);
                ndp[j] = dp[q.front()] + (j - q.front()) / v[i] * w[i];
            }
        }
        dp = move(ndp);
    }

    cout << dp[m] << '\n';
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
