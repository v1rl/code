#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    while(m --) {
        int x, d;
        cin >> x >> d;
        i64 l = x + d - 1, r = l + n;
        i64 L = l;

        auto check = [&](int mid) {
            int nd = mid - L;
            auto pos1 = lower_bound(a.begin(), a.end(), x);
            auto pos2 = lower_bound(a.begin(), a.end(), mid);
            int hs = pos2 - pos1;
            return hs >= nd;
        };

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
