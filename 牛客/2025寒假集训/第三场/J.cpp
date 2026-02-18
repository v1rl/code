#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*

*/

const int mod = 998244353;
const int inf = 1e9 + 7;

void solve() {
    i64 n, q;
    cin >> n >> q;
    while(q --) {
        i64 x;
        cin >> x;
        i64 pos = 63 - __builtin_clzll(x);
        cout << min(n - (1ll << pos) + 1, (1ll << pos)) << '\n';
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