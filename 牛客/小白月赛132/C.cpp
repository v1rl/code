#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;

void solve() {
    i64 l, r;
    cin >> l >> r;

    auto get = [&](i64 x) {
        if(x <= 0) {
            return 0;
        }
        int msb = 63 - __builtin_clzll(x);
        int ans = msb;
        for(int i = msb - 1; i >= 0; i --) {
            if(x >> i & 1) {
                ans += i + 1;
                break;
            }
        }
        ans += msb * (msb - 1) / 2;
        return ans;
    };

    cout << get(r) - get(l - 1) << '\n';
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
