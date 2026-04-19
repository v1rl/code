#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

// https://leetcode.cn/problems/maximal-rectangle/description/

const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n, vector(m, '0'));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> g[i][j];
        }
    }

    vector<int> a(m);
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(g[i][j] == '0') {
                a[j] = 0;
            } else {
                a[j] += 1;
            }
        }

        vector<int> l(m, -1), r(m, m);
        vector<int> stk;
        for(int j = 0; j < m; j ++) {
            while(!stk.empty() && a[stk.back()] >= a[j]) {
                stk.pop_back();
            }
            if(!stk.empty()) {
                l[j] = stk.back();
            }
            stk.push_back(j);
        }
        stk.clear();
        for(int j = m - 1; j >= 0; j --) {
            while(!stk.empty() && a[stk.back()] >= a[j]) {
                stk.pop_back();
            }
            if(!stk.empty()) {
                r[j] = stk.back();
            }
            stk.push_back(j);
        }

        for(int j = 0; j < m; j ++) {
            ans = max(ans, a[j] * (r[j] - l[j] - 1));
        }
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
