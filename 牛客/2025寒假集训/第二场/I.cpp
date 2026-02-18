#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

const int mod = 998244353;
const int inf = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector g(n, vector(m, '0'));
    int cnt[2] {};
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> g[i][j];
            cnt[g[i][j] - '0'] ++;
        }
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cout << (cnt[g[i][j] - '0'] > 1 ? "Y" : "N");
        }
        cout << '\n';
    }
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