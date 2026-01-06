#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;
const int inf = 1e9;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> bit;
    while(n) {
        bit.emplace_back(n % 3);
        k -= n % 3;
        n /= 3;
    }
    if(k < 0) {
        cout << -1 << '\n';
        return;
    }

    for(int i = bit.size() - 1; i > 0; i --) {
        if(i != 0) {
            int d = min(k / 2, bit[i]);
            bit[i] -= d;
            bit[i - 1] += d * 3;
            k -= d * 2;
        }
    }

    i64 ans = 0;
    i64 p = 1;
    for(int i = 0; i < bit.size(); i ++) {
        ans += bit[i] * (3 * p + i * (p / 3));
        p *= 3;
    }
    cout << ans << '\n';
}


signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
}