#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    int lst = -1;

    set<int> S;
    int tar;
    for(int i = 0; i < m; i ++) {
        int x;
        cin >> x;
        tar = a[x] ^ 1;
        S.insert(x);
    }

    vector<int> b;
    vector<int> vis;
    for(int i = 0; i < n; i ++) {
        bool ok = false;
        if(a[i] != lst) {
            b.emplace_back(a[i]);
            lst = a[i];
            vis.emplace_back(ok);
            ok = false;
        } else {
            if(S.count(i)) {
                ok = true;
            }
        }
    }

    int cnt = 0;
    bool ok = false;
    bool ps = false;
    int ans = 0;
    for(int i = 0; i < b.size(); i ++) {
        int res = 0;
        if(b[i] == tar) {
            if(ok) {
                ok = false;
            } else if(ps) {
                ps = false;
                res ++;
            } else {
                cnt ++;
            }
        } else if(vis[i]) {
            if(cnt > 1) {
                ans += 2;
                cnt --;
                ok = true;
            } else if(cnt == 1) {
                res = 2;
                cnt --;
                ps = true;
            } else {
                ans += res;
                res = 0;
            }
        }
    }
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


