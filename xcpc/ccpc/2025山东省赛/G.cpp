#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
typedef pair<int, int> PII;

/*
维护一个区间set
找到左端点，延申左端点或单开
时间单独用变量维护
*/

const int inf = 2e9;

void solve() {
    int n, k;
    cin >> n >> k;
    /*
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        int x, t;
        cin >> x >> t;
        a[i] = t + k - x;
    }

    int ans = 0;
    sort(a.begin(), a.end());
    for(auto x : a) {
        ans = max(ans + 1, x);
    }
    cout << ans << '\n';
    */

    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i ++) {
        int x, t;
        cin >> x >> t;
        a[i] = {x, t};
    }

    sort(a.begin(), a.end(), 
        [&](auto x, auto y) {
            return x[1] < y[1];
        });

    // 先确定到底放在哪个位置（只查不改）
    // 再根据位置确定左右区间以及是否合并
    set<PII> S;
    for(auto [x, t] : a) {
        x = t + k - x;
        int l = x, r = x + 1;
        auto it = S.upper_bound({l, inf});
        if(it != S.begin() && prev(it)->second >= l) {
            l = prev(it)->second;
            r = l + 1;
        }

        it = S.upper_bound({l, inf});
        if(it != S.end()) {
            auto [nl, nr] = *it;
            if(r == nl) {
                r = nr;
                it = S.erase(it);
            }
        }

        if(it != S.begin()) {
            it = prev(it);
            auto [pl, pr] = *it;
            if(l == pr) {
                l = pl;
                S.erase(it);
            }
        }

        S.insert({l, r});
    }

    cout << S.rbegin()->second - 1 << '\n';
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
