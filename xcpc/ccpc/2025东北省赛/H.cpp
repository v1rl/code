#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    i64 sumb = 0;
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
        sumb += b[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> c[i];
    }

    auto check = [&](i64 mid) {
        vector<i64> d(n);
        i64 sumd = 0;
        for(int i = 0; i < n; i ++) {
            d[i] = mid / c[i];
            sumd += d[i];
        }
        bool ok = sumd >= sumb;
        if(!ok) {
            return false;
        }
        for(int i = 0; i < n; i ++) {
            ok &= (sumd - d[a[i] - 1] >= b[i]);
        }
        return ok;
    };

    i64 l = 0, r = 1e18;
    while(l < r) {
        i64 mid = l + r >> 1;
        if(check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
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
