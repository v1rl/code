#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int mod = 998244353;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    int lst = 0;

    for(int i = 1; i <= n; i ++) {
        int x = a[i - 1];
        if((x - 1) / 2 > lst) {
            lst ++;
        } else if(x > lst) {
            lst = x;
        } else {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
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
