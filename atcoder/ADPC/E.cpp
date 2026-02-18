#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
代价范围很大，但是价值的范围很小
考虑以价值为维度，代价为属性 f[前i个物品][价值为j]的最小代价
答案从大到小遍历价值，选取第一个代价合法的价值即可
*/

const i64 inf = 1e18 + 10;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n + 1), w(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> v[i] >> w[i];
    }

    int M = n * 1000;
    vector<i64> f(M + 1, inf);
    f[0] = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = M; j >= w[i]; j --) {
            f[j] = min(f[j], f[j - w[i]] + v[i]);
        }
    }

    for(int j = M; j >= 0; j --) {
        if(f[j] <= m) {
            cout << j << '\n';
            break;
        }
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