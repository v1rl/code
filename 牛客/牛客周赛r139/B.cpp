#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    if(n == 1 && m != 1) {
        string s(m, '1');
        s[0] = '0';
        cout << s << '\n';
    } else if(n != 1 && m == 1) {
        string s(n, '1');
        s[0] = '0';
        for(auto c : s) {
            cout << c << '\n';
        }
    } else {
        cout << -1 << '\n';
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
