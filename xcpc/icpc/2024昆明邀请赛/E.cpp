#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const i64 inf = 1e18;

void solve() {
    int n;
    i64 k;
    cin >> n >> k;
    vector<i64> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector<i64> pre(n + 1), suf(n + 2);
    vector<i64> vec;
    for(int i = 1; i <= n; i ++) {
        pre[i] = gcd(pre[i - 1], a[i]);
        if(pre[i] != pre[i - 1]) {
            vec.emplace_back(i - 1);
        }
    }

    for(int i = n; i >= 1; i --) {
        suf[i] = gcd(suf[i + 1], a[i]);
    }

    auto work = [&](i64 g1, int l) {
        i64 res = 1;
        res = max(res, gcd(g1, gcd(a[l] + k, suf[l + 1])));

        i64 g2 = 0;
        for(int r = l + 1; r <= n; r ++) {
            g2 = gcd(g2, abs(a[r] - a[r - 1]));

            i64 g3 = a[r] + k;

            i64 cur = gcd(g1, gcd(g2, g3));
            i64 g4 = suf[r + 1];
            res = max(res, gcd(cur, g4));
        }
        return res;
    };

    i64 ans = pre[n];
    for(auto l : vec) {
        i64 g1 = pre[l];
        ans = max(ans, work(g1, l + 1));
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