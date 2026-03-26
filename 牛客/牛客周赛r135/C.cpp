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
    if(n >= 4) {
        cout << "YES" << '\n';
        return;
    }
    if(n == 2) {
        if(a[0] == 1) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    } else if(n == 3) {
        if(a[1] == 2) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    } else {
        cout << "YES" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
