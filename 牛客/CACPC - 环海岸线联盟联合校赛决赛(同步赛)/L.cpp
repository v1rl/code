#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    set<int> S[n];
    for(int i = 0; i < n; i ++) {
        int m;
        cin >> m;
        for(int j = 0; j < m; j ++) {
            int x;
            cin >> x;
            S[i].insert(x);
        }
    }

    map<pair<int, int>, int> mp;

    int q;
    cin >> q;
    while(q --) {
        int l, r;
        cin >> l >> r;
        l --, r --;

        if(mp[{l, r}]) {
            cout << mp[{l, r}] << '\n';
            continue;
        }

        if(S[l].size() > S[r].size()) {
            swap(l, r);
        }

        int res = S[r].size();
        for(auto c : S[l]) {
            if(!S[r].count(c)) {
                res ++;
            }
        }

        cout << res << '\n';
        mp[{l, r}] = res;
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
