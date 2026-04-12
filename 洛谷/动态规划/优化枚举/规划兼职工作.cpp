#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/maximum-profit-in-job-scheduling/description/

/*
f[i]表示前i份工作的最大收益
*/

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i][0];
    }
    for(int i = 1; i <= n; i ++) {
        cin >> a[i][1];
    }
    for(int i = 1; i <= n; i ++) {
        cin >> a[i][2];
    }
    a[0].fill(0);
    sort(a.begin(), a.end(), 
        [&](auto &x, auto &y) {
            return x[1] < y[1];
        });

    vector<int> f(n + 1);
    for(int i = 1; i <= n; i ++) {
        int x = a[i][0];

        int l = 0, r = i;
        while(l < r) {
            int mid = l + r >> 1;
            if(a[mid][1] > x) {
                r = mid; 
            } else {
                l = mid + 1;
            }
        }
        l --;

        // cerr << i << ' ' << x << ' ' << l << '\n';
        
        f[i] = max(f[i - 1], f[l] + a[i][2]);
    }

    cout << f[n] << '\n';
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
