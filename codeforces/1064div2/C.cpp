#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

const i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<array<int, 2>> b;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        b.push_back({a[i], i});
    }
    vector<int> ls(n + 1), ne(n + 1);
    for(int i = 1; i <= n; i ++) {
        ls[i] = i - 1;
        ne[i] = i + 1;
    }
    ne[n] = 1, ls[1] = n;

    sort(b.begin(), b.end());
    i64 ans = 0;
    for(int i = 0; i < n - 1; i ++) {
        auto [x, pos] = b[i];
        int l = ls[pos], r = ne[pos];
        int t = a[l] < a[r] ? l : r;
        ans += a[t];
        ne[l] = r;
        ls[r] = l;
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
