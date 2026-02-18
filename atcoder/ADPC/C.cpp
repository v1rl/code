#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/
const int inf = 1e9 + 10;
int f[2][3];

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> w(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> w[i][0] >> w[i][1] >> w[i][2];
    }

    for(int i = 1; i <= n; i ++) {
        int cur = i & 1;
        for(int j = 0; j < 3; j ++) {
            for(int k = 0; k < 3; k ++) {
                if(k == j) {
                    continue;
                }
                f[cur][j] = max(f[cur][j], f[cur ^ 1][k] + w[i][j]);
            }
        }
    }

    cout << max({f[n & 1][0], f[n & 1][1], f[n & 1][2]}) << '\n';
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