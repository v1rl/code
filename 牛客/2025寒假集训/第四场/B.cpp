#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

const int inf = 1e9 + 10;
const int mod = 998244353;

void solve() {
    int n, k, b;
    cin >> n >> k >> b;
    vector<i64> pre(n + 1);
    pre[0] = b;
    for(int i = 1; i <= n; i ++) {
        cin >> pre[i];
        pre[i] += pre[i - 1];
    }

    while(k --) {
        int x, y;
        cin >> x >> y;
        cout << pre[x - 1] + y - 1 << '\n';
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
