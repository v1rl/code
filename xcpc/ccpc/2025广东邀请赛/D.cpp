#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    i64 n;
    cin >> n;
    string s = to_string(n);
    reverse(s.begin(), s.end());

    i64 p2[20];
    p2[0] = 1;
    for(int i = 1; i <= 18; i ++) {
        p2[i] = p2[i - 1] * 2;
    }

    i64 ans = 0;
    int t = 0;
    for(auto c : s) {
        ans += p2[t ++] * (c - '0');
    }
    cout << ans << '\n';
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
