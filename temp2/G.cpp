#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
预处理所有数在序列中出现的位置mp
对于每个询问，得到两个vec序列，用一个类似二分查找的方式向右遍历
*/

void solve() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<int>> mp;
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        mp[x].emplace_back(i);
    }

    map<array<int, 2>, i64> ansmp;
    while(m --) {
        int l, r;
        cin >> l >> r;
        if(l == r) {
            int siz = mp[l].size();
            cout << 1ll * siz * (siz - 1) / 2 << '\n';
        } else if(ansmp.count({l, r})) {
            cout << ansmp[{l, r}] << '\n';
        } else {
            auto &x = mp[l];
            auto &y = mp[r];

            int sizx = x.size(), sizy = y.size();
            int posx = 0, posy = 0;

            int res = 0;
            i64 ans = 0;
            while(posx != sizx && posy != sizy) {
                int curx = x[posx], cury = y[posy];
                if(curx < cury) {
                    int nex = upper_bound(x.begin() + posx, x.end(), cury) - x.begin() - 1;
                    res += nex - posx + 1;
                    ans += res;
                    posx = nex + 1, posy ++;
                } else {
                    int ney = upper_bound(y.begin() + posy, y.end(), curx) - y.begin() - 1;
                    ans += 1ll * (ney - posy + 1) * res;
                    posy = ney + 1;
                }
            }

            if(posy != sizy) {
                ans += 1ll * (sizy - posy) * res;
            }

            ansmp[{l, r}] = ans;
            cout << ans << '\n';
        }
    }
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