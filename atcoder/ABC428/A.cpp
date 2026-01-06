#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

const i64 inf = 1e18;

void solve() {
    int s, a, b, x;
    cin >> s >> a >> b >> x;
    int sum = a + b;
    int ans = x / sum * s * a + min(a, x % sum) * s;
    cout << ans << '\n';
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