#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;
#define int long long

const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    multiset<pair<i64, int>> S;

    i64 lst = 0;
    int snum = 0;

    auto it = S.begin();
    bool f = false;
    int cnt = 0;

    for(int i = 0; i < n; i ++) {
        int op;
        cin >> op;
        if(op == 1) {
            i64 x;
            cin >> x;
            S.insert({x, cnt});
            if(!f) {
                it = S.begin();
                f = true;
            }
            cnt ++;
        } else if(op == 2) {
            int k;
            cin >> k;
            k = cnt - k;

            if(snum < k) {
                while(snum < k) {
                    snum ++;
                    it ++;
                }
            } else {
                while(snum > k) {
                    it --;
                    snum --;
                }
            }

            cout << lst + it->first << '\n';
            lst = it->first;
        } else {
            cout << lst + cnt << '\n';
            lst = cnt;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;

    while(t --) {
        solve();
    }

    return 0;
}

