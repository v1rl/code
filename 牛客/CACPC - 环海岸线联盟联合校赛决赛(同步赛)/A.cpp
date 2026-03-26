#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(), a.end());

    auto check = [&](int mid) {
        i64 res = 0;
        for(auto [t, v] : a) {
            if(t >= mid) {
                res += v;
            }
        }
        return res >= m;
    };

    int l = 0, r = 1e9;
    while(l < r) {
        int mid = l + r + 1 >> 1;
        if(check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << '\n';
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
