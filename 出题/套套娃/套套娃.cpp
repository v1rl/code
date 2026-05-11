#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<i64> pre(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> pre[i];
    }
    for(int i = 1; i <= n; i ++) {
        pre[i] += pre[i - 1];
    }
    for(int i = 1; i <= n; i ++) {
        pre[i] += pre[i - 1];
    }
    for(int i = 1; i <= n; i ++) {
        cout << pre[i] << " \n"[i == n];
    }
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
