#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*
*/

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for(auto c : s) {
        if(c == '1') {
            ans ++;
        }
    }


    int cnt = 0;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '0') {
            cnt ++;
        } else {
            int num = cnt - 1;
            if(num > 0) {
                ans += (num + 3 - 1) / 3;
            }
            cnt = -1;
        }
    }

    if(cnt > 0) {
        ans += (cnt + 3 - 1) / 3;
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