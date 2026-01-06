#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

// https://codeforces.com/contest/2014/problem/H

constexpr int V = 1e6;
vector<u64> val(V + 1);

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> pre(n + 1);
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        pre[i] = pre[i - 1] ^ val[x];
    }

    for(int i = 1; i <= q; i ++) {
        int l, r;
        cin >> l >> r;
        if(pre[l - 1] == pre[r]) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= V; i ++) {
        val[i] = rng();
    }
    while(t --) {
        solve();
    }


}