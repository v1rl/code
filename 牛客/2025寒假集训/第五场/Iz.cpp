#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<i64, i64> PII;

/*
*/

void solve() {
    int n, m;
    i64 h;
    cin >> n >> m >> h;

    vector<int> p(m + 1), f(m + 1);
    for(int i = 1; i <= m; i ++) {
        cin >> p[i] >> f[i];
    }

    vector<i64> d0(n + 1), d1(n + 1);
    int cur = 0;
    int l = 1, r = m + 1;

    auto check = [&](int mid) {
        i64 k = 0, d = 0;
        for(int i = 1; i <= n; i ++) {
            k += d1[i];
            d += d0[i];
            if(k * i + d > h) {
                return true;
            }
        }
        return false;
    };

    while(l < r) {
        int mid = l + r >> 1;

        for(int i = cur + 1; i <= mid; i ++) {
            int L = max(1, p[i] - f[i] + 1);
            d1[L] ++;
            d0[L] += f[i] - p[i];
            d1[p[i]] --;
            d0[p[i]] -= f[i] - p[i];

            int R = min(n + 1, p[i] + f[i]);
            d1[p[i]] --;
            d0[p[i]] += f[i] + p[i];
            if(R <= n) {
                d1[R] ++;
                d0[R] -= f[i] + p[i];
            }
        }

        for(int i = cur; i > mid; i --) {
            int L = max(1, p[i] - f[i] + 1);
            d1[L] --;
            d0[L] -= f[i] - p[i];
            d1[p[i]] ++;
            d0[p[i]] += f[i] - p[i];

            int R = min(n + 1, p[i] + f[i]);
            d1[p[i]] ++;
            d0[p[i]] -= f[i] + p[i];
            if(R <= n) {
                d1[R] --;
                d0[R] += f[i] + p[i];
            }
        }

        cur = mid;

        if(check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    if(l == m + 1) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
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
