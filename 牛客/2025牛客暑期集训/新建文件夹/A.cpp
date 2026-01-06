#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    i64 n;
    cin >> n;

    if(n == 0) {
        cout << 10 << '\n';
        return;
    }

    bool f = false;

    u64 x;
    if(n < 0) {
        x = -n;
        f = true;
    } else {
        x = n;
    }

    u64 t = x;
    int p = 0;
    while(t) {
        t /= 10;
        p ++;
    }

    u64 x1 = x * 10 + 1;
    u64 x2 = pow(10, p) + x;

    if(f) {
        cout << '-';
        cout << min(x1, x2) << '\n';
    } else {
        cout << max(x1, x2) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
}