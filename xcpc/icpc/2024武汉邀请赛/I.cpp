#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] == '1' && (i == 0 || s[i - 1] == '0')) {
            ans ++;
        }
    }
    if(s.back() == '1') {
        ans --;
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
