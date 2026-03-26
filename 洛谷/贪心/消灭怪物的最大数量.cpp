#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://leetcode.cn/problems/eliminate-maximum-number-of-monsters/description/

void solve() {
    int n;
    cin >> n;
    vector<int> d(n), v(n);
    for(int i = 0; i < n; i ++) {
        cin >> d[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> v[i];
    }

    vector<int> t(n);
    for(int i = 0; i < n; i ++) {
        t[i] = (d[i] + v[i] - 1) / v[i];
    }

    sort(t.begin(), t.end());

    for(int i = 0; i < n; i ++) {
        if(t[i] < i + 1) {
            cout << i << '\n';
            return;
        }
    }
    cout << n << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}