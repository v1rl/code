#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
*/

void solve() {
    int n;
    cin >> n;
    if(n == 1 || n == 2 || n == 4) {
        cout << -1 << '\n';
        return;
    }
    if(n & 1) {
        for(int i = 1; i <= n / 2 + 1; i ++) {
            cout << i << ' ';
        }
        for(int i = n / 2; i >= 1; i --) {
            cout << i << ' ';
        }
        cout << '\n';
    } else {
        cout << 1 << ' ' << 2 << ' ' << 1 << ' ';
        n -= 3;
        for(int i = 1; i <= n / 2 + 1; i ++) {
            cout << i << ' ';
        }
        for(int i = n / 2; i >= 1; i --) {
            cout << i << ' ';
        }
        cout << '\n';
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
