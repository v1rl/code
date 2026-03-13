#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/description/

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    int l = -1, r = -1;
    int mx = -inf;
    for(int i = 0; i < n; i ++) {
        if(a[i] >= mx) {
            mx = a[i];
        } else {
            r = i;
        }
    }
    int mn = inf;
    for(int i = n - 1; i >= 0; i --) {
        if(a[i] <= mn) {
            mn = a[i];
        } else {
            l = i;
        }
    }
    if(l == -1) {
        cout << 0 << '\n';
    } else {
        cout << r - l + 1 << '\n';
    }
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