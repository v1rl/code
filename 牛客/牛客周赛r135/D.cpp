#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 ceil(i64 x, i64 y) {
    return x > 0 ? (x + y - 1) / y : x / y;
}

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    i64 sum = accumulate(a.begin(), a.end(), 0ll);
    int v = ceil(sum, n);
    i64 ans = 0;
    for(int i = 0; i < n; i ++) {
        ans += max(0, v - a[i]);
    }
    cout << ans << '\n';
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
