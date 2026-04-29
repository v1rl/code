#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    vector<int> a(n + 1);
    iota(a.begin(), a.end(), 0);
    vector<int> b = a;
    int T = -1;
    for(int i = 0; i < m; i ++) {
        reverse(a.begin() + a1, a.begin() + a2 + 1);
        reverse(a.begin() + b1, a.begin() + b2 + 1);
        if(b == a) {
            T = i + 1;
            break;
        }
    }

    if(T == -1) {
        for(int j = 1; j <= n; j ++) {
            cout << a[j] << '\n';
        }
        return;
    }

    m %= T;
    a = b;
    for(int i = 0; i < m; i ++) {
        reverse(a.begin() + a1, a.begin() + a2 + 1);
        reverse(a.begin() + b1, a.begin() + b2 + 1);
    }

    for(int j = 1; j <= n; j ++) {
        cout << a[j] << '\n';
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
