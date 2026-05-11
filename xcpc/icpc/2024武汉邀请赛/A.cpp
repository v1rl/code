#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    i64 sum = 0;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        sum += x;
    }

    i64 ans = 0;
    for(int i = 40; i >= 0; i --) {
        if(sum <= 0) {
            break;
        }
        i64 nd = ((1ll << i) - 1) * n;
        if(sum > nd) {
            sum -= min<i64>(n, sum / (1ll << i)) * (1ll << i);
            ans += 1ll << i;
        }
    }

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
