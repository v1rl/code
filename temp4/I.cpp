#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;
#define int long long

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> kth;
    vector<int> a(n);
    vector<int> v(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        kth.emplace_back(a[i]);
    }
    for(int i = 0; i < n; i ++) {
        cin >> v[i];
    }

    int q;
    cin >> q;
    vector<array<int, 2>> query;
    vector<int> ans(q);
    for(int i = 0; i < q; i ++) {
        int l, r;
        cin >> l >> r;
        kth.emplace_back(l);
        kth.emplace_back(r);
        query.push_back({l, r});
    }

    sort(kth.begin(), kth.end());
    kth.erase(unique(kth.begin(), kth.end()), kth.end());
    int N = kth.size();
    kth.insert(kth.begin(), 0);

    auto rank = [&](int x) {
        return lower_bound(kth.begin() + 1, kth.end(), x) - kth.begin();
    };

    vector<int> pre(N + 1);
    for(int i = 0; i < n; i ++) {
        int pos = rank(a[i]);
        pre[pos] += v[i];
    }

    for(int i = 1; i <= N; i ++) {
        pre[i] += pre[i - 1];
        pre[i] %= mod;
    }

    for(auto [l, r] : query) {
        int L = rank(l), R = rank(r);
        cout << ((pre[R] - pre[L]) % mod + mod) % mod << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --) {
        solve();
    }

    return 0;
}

