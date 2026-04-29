#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    i64 a, b;
    cin >> a >> b;

    while(1) {
        i64 g = gcd(a, b);
        if(g == 1) {
            break;
        }
        b /= g;
    }

    if(b == 1) {
        cout << -1 << '\n';
    } else {
        cout << b << '\n';
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
