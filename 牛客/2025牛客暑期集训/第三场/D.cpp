#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, a;
    cin >> n >> a;
    string s;
    cin >> s;
    s = '#' + s;
    int res = 0;
    int num = 0;
    for(int i = 1; i <= n; i ++) {
        if(s[i] == '1') {
            num ++;
            res ++;
        } else {
            if(num >= a) {
                cout << n << '\n';
                return;
            }
            num = 0;
        }
    }
    if(num >= a) {
        cout << n << '\n';
        return;
    }
    
    num = 0;
    for(int i = 1; i <= n; i ++) {
        if(s[i] == '0') {
            num ++;
        } else {
            if(num >= a + 1) {
                cout << n << '\n';
                return;
            }
            num = 0;
        }
    }
    if(num >= a + 1) {
        cout << n << '\n';
        return;
    }

    cout << res << '\n';
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --)
    {
        solve();
    }
}