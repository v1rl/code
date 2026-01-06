#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '#' + s;

    int ans = 1e9;

    for(int i = 1; i <= n - 3; i ++) {
        for(int j = i + 1; j <= n - 2; j ++) {
            int res = 0;
            for(int k = j + 1; k <= n - 1; k ++) {
                if(k == j + 1) {
                    for(int x = 1; x <= n; x ++) {
                        if(x <= i && s[x] != '0') {
                            res ++;
                        } else if(x > i && x <= j && s[x] != '1') {
                            res ++;
                        } else if(x > j && x <= k && s[x] != '0') {
                            res ++;
                        }  else if(x > k && s[x] != '1') {
                            res ++;
                        }
                    }
                } else {
                    if(s[k] != '0') {
                        res ++;
                    } else {
                        res --;
                    }
                }
                ans = min(ans, res);
            }
        }
    }

    // cout << ans << '\n';

    for(int i = 1; i <= n - 3; i ++) {
        for(int j = i + 1; j <= n - 2; j ++) {
            int res = 0;
            for(int k = j + 1; k <= n - 1; k ++) {
                if(k == j + 1) {
                    for(int x = 1; x <= n; x ++) {
                        if(x <= i && s[x] == '0') {
                            res ++;
                        } else if(x > i && x <= j && s[x] == '1') {
                            res ++;
                        } else if(x > j && x <= k && s[x] == '0') {
                            res ++;
                        } else if(x > k && s[x] == '1') {
                            res ++;
                        }
                    }
                } else {
                    if(s[k] == '0') {
                        res ++;
                    } else {
                        res --;
                    }
                }
                ans = min(ans, res);
            }
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --)
    {
        solve();
    }
}