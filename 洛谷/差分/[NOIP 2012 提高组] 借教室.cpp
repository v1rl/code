#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

/*
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector<array<int, 3>> q(m + 1);
    for(int i = 1; i <= m; i ++) {
        cin >> q[i][0] >> q[i][1] >> q[i][2];
    }

    vector<i64> d(n + 2);
    int l = 0, r = m;
    int cur = 0;

    auto check = [&]() {
        i64 s = 0;
        for(int i = 1; i <= n; i ++) {
            s += d[i];
            if(s > a[i]) {
                return false;
            }
        }
        return true;
    };

    while(l < r) {
        int mid = l + r + 1 >> 1;

        for(int i = cur + 1; i <= mid; i ++) {
            auto &[c, l, r] = q[i];
            d[l] += c;
            d[r + 1] -= c;
        }

        for(int i = cur; i > mid; i --) {
            auto &[c, l, r] = q[i];
            d[l] -= c;
            d[r + 1] += c;
        }

        cur = mid;

        if(check()) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    if(l == m) {
        cout << 0 << '\n';
    } else {
        cout << -1 << '\n' << l + 1 << '\n';
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
