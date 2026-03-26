#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7;

void solve() {
    int n, k, m, x;
    cin >> n >> k >> m >> x;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }


    auto check = [&](i64 mid) {
        vector<int> res;
        int cnt = 0;
        for(int i = 1; i <= n; i ++) {
            if(a[i] >= mid) {
                cnt ++;
            } else if(a[i] + x >= mid) {
                res.emplace_back(i);
            }
        }

        int mx = 0;
        for(int i = 0; i < res.size(); i ++) {
            int pos = res[i];

            int npos = upper_bound(res.begin(), res.end(), pos + m - 1) - res.begin();
            // if(mid == 1) {
            //     cout << npos << ' ' << i << '\n';
            // }
            mx = max(mx, npos - i);
        }

        return cnt + mx >= k;
    };

    i64 l = 0, r = 2e9;
    while(l < r) {
        i64 mid = l + r + 1 >> 1;
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
    cin >> t;
    while(t --) {
        solve();
    }


    return 0;
}
