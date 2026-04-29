#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const i64 inf = 1e18;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = s + s;

    int stt = -1;
    for(int i = 1; i < n; i ++) {
        if(s[i] != s[i - 1]) {
            stt = i;
            break;
        }
    }

    if(stt == -1) {
        cout << n / 2 << '\n';
        return;
    }

    bool f = false;
    int ans = 0;
    int cnt = 1;
    for(int i = stt + 1; i < stt + n; i ++) {
        if(s[i] == s[i - 1]) {
            cnt ++;
        } else {
            if(cnt % 2 == 0) {
                f = true;
            }
            ans += cnt / 2;
            cnt = 1;
        }
    }
    if(cnt % 2 == 0) {
        f = true;
    }
    ans += cnt / 2;

    if(f) {
        ans --;
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