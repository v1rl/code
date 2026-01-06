#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long
const int inf = 2e18;
const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    // cerr << 'h';
    n --;
    if(n % 3 == 0 && (n / 3) % 2 == 1) {
        cout << 2 << '\n';
    } else {
        cout << 0 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;  
    cin >> t;
    while(t --) {
        solve();
    }
}