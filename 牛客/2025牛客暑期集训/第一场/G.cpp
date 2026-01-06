#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// 读明白题

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    while(q --) {
        string t;
        int z;
        cin >> t >> z;
        z --;

        int res = 0;
        i64 ans = 0;
        for(int i = z, j = 0; j < t.size(); i ++, j ++) {
            if(s[i] == t[j]) {
                res ++;
            } else {
                ans += 1ll * res * (res + 1) / 2;
                res = 0;
            }
        }
        ans += 1ll * res * (res + 1) / 2;
        cout << ans << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --)
    {
        solve();
    }
}