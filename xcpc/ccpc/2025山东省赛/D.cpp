#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    i64 s = 0;
    for(int i = 0; i < q; i ++) {
        int x, k;
        cin >> x >> k;
        s += x / n;
        int lst = x % n;
        if(k + lst <= n) {
            a[k] += 1;
            a[k + lst] -= 1;
        } else {
            a[k] += 1;
            a[n] -= 1;
            int t = k + lst - n;
            a[0] += 1;
            a[t] -= 1;
        }
    }

    for(int i = 0; i < n; i ++) {
        if(i != 0) {
            a[i] += a[i - 1];
        }
        cout << a[i] + s << ' ';
    }
    cout << '\n';
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
