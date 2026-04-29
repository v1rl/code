#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    i64 ans = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            int x = (i - 1) * n + j;
            if(i == j || i == j + 1) {
                ans += x;
            }
        }
    }
    ans += n;
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
