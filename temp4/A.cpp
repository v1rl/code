#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;
#define int long long

const int N = 1e6 + 10;

void solve() {
    int n, x;
    cin >> x >> n;
    if(n & 1) {
        cout << "Yes" << '\n';
        cout << x << ' ';

        int p = x + 1;
        if(x < 0) {
            p = x - 1;
        }

        for(int i = 1; i <= n - 1; i ++) {
            if(i & 1) {
                cout << p << ' ';
            } else {
                cout << -p << ' ';
                if(x < 0) {
                    p --;
                } else {
                    p ++;
                }
            }
        }
        cout << '\n';

    } else if(n == 2) {
        if(abs(x) == 1) {
            cout << "No" << '\n';
            return;
        }

        cout << "Yes" << '\n';
        if(x % 2 == 0) {
            cout << x / 2 << ' ' << -x << '\n';
        } else {
            cout << x - 1 << ' ' << -(x - 1) * x << '\n';
        }
    } else {
        cout << "Yes" << '\n';
        i64 t = 1e6 + 1;
        cout << x << ' ';
        cout << t << ' ' << -(t + 1) << ' ' << -(t + 1) * t << ' ';
        n -= 4;

        t = t + 2;
        for(int i = 1; i <= n; i ++) {
            if(i & 1) {
                cout << t << ' ';
            } else {
                cout << -t << ' ';
                t ++;
            }
        }
        cout << '\n';
    } 
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --) {
        solve();
    }

    return 0;
}

