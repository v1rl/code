#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    if(n >= 2 && m >= 2) {
        int u = (n - 2) * 2 + 2;
        if(m > u) {
            cout << "impossible" << '\n';
        } else {
            int d = m - 2;

            while(d > 1) {
                cout << 2 << ' ' << 100 << '\n';
                d -= 2;
                n --;
            }
            if(d & 1) {
                cout << 1 << ' ' << 50 << '\n';
                d --;
                n --;
            }
            
            cout << 1 << ' ' << 30 << '\n';
            cout << 2 << ' ' << 32 << '\n';
            n -= 2;

            while(n) {
                cout << 1 << ' ' << 1 << '\n';
                n --;
            }
        }
    } else {
        cout << "impossible" << '\n';
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
