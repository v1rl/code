#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
f[前i个物品][代价最多为j]的最大价值
*/

const int inf = 1e9 + 10;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n + 1), w(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> v[i] >> w[i];
    }

    vector<i64> f(m + 1);
    for(int i = 1; i <= n; i ++) {
        for(int j = m; j >= v[i]; j --) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    cout << f[m] << '\n';
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