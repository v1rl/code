#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long
const int inf = 2e18;
const int mod = 998244353;

void solve() {
    string s;
    cin >> s;
    if(s[0] == '0' && s[2] != '0' && s[1] == '-') {
        cout << "Yes" << '\n';
        return;
    }

    if(s[0] == s[2] || s[1] == '-') {
        cout << "No" << '\n';
    } else {
        cout << "Yes" << '\n';
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