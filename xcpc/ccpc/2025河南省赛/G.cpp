#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    if(n == 4) {
        cout << -1 << '\n';
        return;
    }

    int t = (n - 2) / 3 + 1;
    int idx = 1;
    for(int i = 0; i < t; i ++) {
        cout << 1 << ' ' << ++ idx << '\n';
    }

    bool f = false;
    if(n % 3 == 1) {
        n -= t + 2;
        f = true;
    } else {
        n -= t + 1;
    }
    int lst = 1;


    while(n --) {
        cout << lst << ' ' << ++ idx << '\n';
        lst = idx;
    }
    if(f) {
        cout << idx - 2 << ' ' << ++ idx << '\n';
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
