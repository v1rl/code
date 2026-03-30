#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*
*/

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    cout << n / 3600 << ' ' << (n % 3600) / 60 << ' ' << n % 60 << '\n';
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
