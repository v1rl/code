#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://www.luogu.com.cn/problem/P12331

void solve() {
    // 贪心暴力取最大
    int n, m;
    cin >> n >> m;

    priority_queue<array<i64, 4>> heap;

    for(int i = 0; i < m; i ++) {
        int k, x;
        cin >> k >> x;
        heap.push({k + x, k, x, 1});
    }

    i64 res = 0;
    while(n && heap.size() && heap.top()[0] > 0) {
        auto [v, k, x, num] = heap.top();
        heap.pop();
        res += v;
        n --;

        i64 nv = num * k + x + k * (num + 1);
        heap.push({nv, k, x, num + 1});
    }

    cout << res << '\n';

    /*
    // 贪心二分
    i64 n;
    int m;
    cin >> n >> m;

    vector<array<int, 2>> a(m);

    for(int i = 0; i < m; i ++) {
        cin >> a[i][0] >> a[i][1];
    }

    auto check = [&](int mid) {
        i64 res = 0;
        for(auto [k, x] : a) {
            if(-k >= x) {
                continue;
            }
            int up = mid - x - k;
            int down = k * 2;
            if(up > 0) {
                continue;
            }
            int cnt = up / down + 1;
            res += max<int>(0, cnt);
        }
        return res >= n;
    };

    int l = 0, r = 1e5;
    while(l < r) {
        int mid = l + r + 1 >> 1;
        if(check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    auto get = [&](int mid) {
        i64 ans = 0;
        i64 sel = 0;
        for(auto [k, x] : a) {
            int up = mid - x - k;
            int down = k * 2;
            if(up > 0) {
                continue;
            }
            int cnt = up / down + 1;

            sel += cnt;
            ans += 1ll * cnt * (x + k) + 1ll * cnt * (cnt - 1) * k;
        }
        return ans - (sel - n) * mid;
    };

    cout << get(l) << '\n';
    */
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}