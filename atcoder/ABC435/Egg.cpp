#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
*/

void solve() {
    int n, m;
    cin >> m >> n;
    map<int, int> mp;
    int res = 0;
    for(int i = 0; i < n; i ++) {
        int l, r;
        cin >> l >> r;
        r ++;
        auto pos = mp.lower_bound(l);
        if(pos != mp.begin() && prev(pos)->second > l) {
            pos --;
        }
        while(pos != mp.end() && pos->first < r) {
            auto [nl, nr] = *pos;
            res -= nr - nl;
            l = min(nl, l);
            r = max(nr, r);
            pos = mp.erase(pos);
        }
        mp[l] = r;
        res += r - l;
        cout << m - res << '\n';
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
