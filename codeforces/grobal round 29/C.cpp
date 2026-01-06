#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

/*
连续的0
单个1隔开的0
在边上的0
*/

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> res;
    int cnt = 0;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '1') {
            if(cnt) {
                res.emplace_back(cnt);
            }
            cnt = 0;
            res.emplace_back(0);
        } else {
            cnt ++;
        }
    }
    if(cnt) {
        res.emplace_back(cnt);
    }

    // for(auto c : res) {
    //     cout << c << '\n';
    // }

    int siz = res.size();
    vector<int> st(siz + 1);
    for(int i = 0; i < siz; i ++) {
        if(st[i]) {
            continue;
        }
        if(res[i] > 1 || res[i] == 0) {
            continue;
        } else {
            // cerr << res[i] << ' ';
            if(i == 0 || i == siz - 1) {
                continue;
            }
            if(i - 2 >= 0 && (!st[i - 2] && res[i - 2] > 0)) {
                continue;
            }
            if(i + 2 < siz && res[i + 2] > 0) {
                if(res[i + 2] == 1) {
                    st[i + 2] = true;
                }
                continue;
            }
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}