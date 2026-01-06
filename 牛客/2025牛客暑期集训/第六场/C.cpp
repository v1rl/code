#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
#define int long long
const int inf = 1e9;
const int mod = 998244353;

// 新增一个数时，它只有放在最后一位才会有效
// 乘以(n - 1) + 整体加1
// 1
// 1 1
// 2 3 1
// (6 9 3) + (0 2 3 1)

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> query;
    query.reserve(n);
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        query.push_back({x, i});
    }

    sort(query.begin(), query.end());
    vector<int> ans(n + 1);

    vector<int> A(500001);
    A[1] = 1;
    for(int i = 2; i <= 500000; i ++) {
        A[i] = A[i - 1] * i % mod;
    }

    int cnt = 0;
    array<int, 3> f[2] = {{0, 0, 0}, {0, 0, 0}};
    f[1][0] = f[1][1] = f[1][2] = 1;
    while(cnt < n && query[cnt][0] == 1) {
        ans[query[cnt][1]] = 1;
        cnt ++;
    }
    for(int i = 2; i <= 500000; i ++) {
        int cur = i & 1;
        int lst = cur ^ 1;
        f[cur][0] = f[lst][0] + A[i - 1];
        f[cur][0] %= mod;
        f[cur][1] = f[lst][1] + 2 * f[lst][0] % mod + A[i - 1];
        f[cur][1] %= mod;
        f[cur][2] = f[lst][2] + 3 * (f[lst][1] + f[lst][0]) % mod + A[i - 1];
        f[cur][2] %= mod;

        f[cur][0] += f[lst][0] * (i - 1) % mod;
        f[cur][1] += f[lst][1] * (i - 1) % mod;
        f[cur][2] += f[lst][2] * (i - 1) % mod;
        f[cur][0] %= mod;
        f[cur][1] %= mod;
        f[cur][2] %= mod;

        while(cnt < n && query[cnt][0] == i) {
            ans[query[cnt][1]] = f[cur][2];
            cnt ++;
        }
    }

    for(int i = 1; i <= n; i ++) {
        cout << ans[i] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
}