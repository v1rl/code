#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
*/

void solve() {
    int n, m;
    cin >> m >> n;
    set<array<int, 2>> S;
    S.insert({1, m + 1});
    int res = m;

    for(int i = 0; i < n; i ++) {
        int l, r;
        cin >> l >> r;
        r ++;
        auto pos = S.upper_bound({l, l});
        if(pos != S.begin() && (*prev(pos))[1] > l) {
            pos --;
        }

        vector<array<int, 2>> add;

        while(pos != S.end() && (*pos)[0] < r) {
            auto [sl, sr] = *pos;

            if(sl <= l) {
                if(sr <= r) {
                    add.push_back({sl, l});
                } else {
                    add.push_back({sl, l});
                    add.push_back({r, sr});
                }
            } else if(sl < r) {
                if(sr <= r) {
                    ;
                } else {
                    add.push_back({r, sr});
                }
            }

            pos = S.erase(pos);
            res -= sr - sl;
        }

        for(auto [x, y] : add) {
            res += y - x;
            S.insert({x, y});
        }

        cout << res << '\n';
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
