#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://leetcode.cn/problems/minimum-cost-for-tickets/description/

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    int v[3];
    int w[3] = {1, 7, 30};
    for(int i = 0; i < 3; i ++) {
        cin >> v[i];
    }

    /*
    // 二分
    vector<int> f(n, inf);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < 3; j ++) {
            auto it = lower_bound(a.begin(), a.end(), a[i] - w[j] + 1);
            int pos = it - a.begin();
            pos --;
            if(pos == -1) {
                f[i] = min(f[i], v[j]);
            } else {
                f[i] = min(f[i], f[pos] + v[j]);
            }
        }
    }
    cout << f[n - 1] << '\n';
    */

    // 单调指针
    int p[3] {};
    vector<int> f(n, inf);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < 3; j ++) {
            while(p[j] < n && a[p[j]] < a[i] - w[j] + 1) {
                p[j] ++;
            }
            int pos = p[j] - 1;
            if(pos == -1) {
                f[i] = min(f[i], v[j]);
            } else {
                f[i] = min(f[i], f[pos] + v[j]);
            }
        }
    }
    cout << f[n - 1] << '\n';
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
