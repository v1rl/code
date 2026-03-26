#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    if(n == 3) {
        cout << -1 << '\n';
        return;
    } else if(n == 4) {
        cout << 1 << ' ' << 2 << '\n';
        cout << 2 << ' ' << 4 << '\n';
        cout << 4 << ' ' << 3 << '\n';
        return;
    }
    
    int n1 = (n + 1) / 2, n0 = n / 2;
    int c1 = 1, c0 = 2;
    if(n1 & 1) {
        int t = c0;
        for(int i = 0; i < n1; i ++) {
            cout << t << ' ' << c1 << '\n';
            c0 += 2;
            if(c0 <= n) {
                cout << c0 << ' ' << c1 << '\n';
            }
            c1 += 2;
        }
    } else {
        int t = c0;
        n -= 4;
        for(int i = 0; i < n1 - 1; i ++) {
            cout << t << ' ' << c1 << '\n';
            if(c0 + 2 <= n) {
                // cerr << 'h';
                c0 += 2;
                cout << c0 << ' ' << c1 << '\n';
            }
            c1 += 2;
        }
        c0 += 2;
        cout << c1 - 2 << ' ' << c0 << '\n';
        c0 += 2;
        cout << c0 - 2 << ' ' << c0 << '\n';
        cout << c0 << ' ' << c1 << '\n';
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
