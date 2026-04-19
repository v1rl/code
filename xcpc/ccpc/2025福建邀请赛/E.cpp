#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> a, b;
    for(int i = 1; i <= n * 2; i ++) {
        int x;
        cin >> x;
        if(i & 1) {
            a.emplace_back(x);
        } else {
            b.emplace_back(x);
        }
    }

    auto na = a, nb = b;
    na.erase(na.begin(), na.begin() + 1);
    nb.pop_back();

    i64 sa = accumulate(a.begin(), a.end(), 0ll);
    i64 sb = accumulate(b.begin(), b.end(), 0ll);
    if(sa > sb) {
        swap(sa, sb);
        swap(na, nb);
        swap(a, b);
    }
    i64 d = sb - sa;
    i64 ans = min(sa, sb);

    auto work = [&](vector<int> &a, vector<int> &b) {
        int n = a.size();
        vector<int> c(n);
        for(int i = 0; i < n; i ++) {
            c[i] = b[i] - a[i];
        }

        vector<i64> pre(n + 1);
        for(int i = 1; i <= n; i ++) {
            pre[i] = pre[i - 1] + c[i - 1];
        }

        set<i64> S;
        for(auto x : pre) {
            i64 tar = x - d / 2;
            auto it = S.lower_bound(tar);
            if(it != S.end()) {
                i64 v = x - *it;
                ans = max(ans, min(sa + v, sb - v));
            }
            if(it != S.begin()) {
                it --;
                i64 v = x - *it;
                ans = max(ans, min(sa + v, sb - v));
            }
            S.insert(x);
        }
    };

    work(a, b);
    work(na, nb);

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
