#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

int cnt[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

void solve() {
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < 26; i ++) {
        int res = 0;
        for(auto c : s) {
            int ch = (c - 'A' + i) % 26;
            res += cnt[ch];
        }
        ans = max(ans, res);
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
