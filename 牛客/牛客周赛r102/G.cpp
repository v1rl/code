#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

constexpr int V = 2e5;
vector<u64> val(V + 1);

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, q;
    cin >> n >> q;
    vector<u64> sum(n + 1);
    vector<u64> psum(V + 1);

    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        sum[i] = sum[i - 1] + val[x];
    }

    for(int i = 1; i <= V; i ++) {
        psum[i] = psum[i - 1] + val[i] * 2;
    }

    for(int i = 1; i <= q; i ++) {
        int l, r;
        cin >> l >> r;
        if(sum[r] - sum[l - 1] == psum[(r - l + 1) / 2]) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= V; i ++) {
        val[i] = rng();
    }
    while(t --) {
        solve();
    }
}