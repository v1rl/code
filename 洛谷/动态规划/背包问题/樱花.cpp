#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://www.luogu.com.cn/problem/P1833

/*
*/

const int mod = 1e9 + 7;

void solve() {
    string s, t;
    cin >> s >> t;

    int h1, m1, h2, m2;
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] == ':') {
            h1 = stoi(s.substr(0, i));
            m1 = stoi(s.substr(i + 1));
            break;
        }
    }

    for(int i = 0; i < t.size(); i ++) {
        if(t[i] == ':') {
            h2 = stoi(t.substr(0, i));
            m2 = stoi(t.substr(i + 1));
            break;
        }
    }

    int m = (h2 - h1) * 60 + (m2 - m1);

    int n;
    cin >> n;

    vector<int> v(n), w(n), c(n);
    for(int i = 0; i < n; i ++) {
        cin >> v[i] >> w[i] >> c[i];
    }

    vector<int> dp(m + 1);

    for(int i = 0; i < n; i ++) {
        vector<int> ndp(m + 1);
        if(c[i] == 0) {
            for(int j = 0; j <= m; j ++) {
                ndp[j] = dp[j];
                if(j >= v[i]) {
                    ndp[j] = max(ndp[j], ndp[j - v[i]] + w[i]);
                }
            }
        } else {
            for(int k = 0; k < min(v[i], m + 1); k ++) {
                deque<int> q;
                for(int j = k; j <= m; j += v[i]) {
                    if(q.size() && q.front() < j - c[i] * v[i]) {
                        q.pop_front();
                    }
                    while(q.size() && dp[q.back()] + (j - q.back()) / v[i] * w[i] <= dp[j]) {
                        q.pop_back();
                    }
                    q.push_back(j);
                    ndp[j] = dp[q.front()] + (j - q.front()) / v[i] * w[i];
                }
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
