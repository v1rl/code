#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/russian-doll-envelopes/description/

/*
*/

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }

    sort(a.begin(), a.end(), 
        [&](auto &x, auto &y) {
            if(x[0] == y[0]) {
                return x[1] > y[1];
            }
            return x[0] < y[0];
        });

    vector<int> ed;
    for(int i = 0; i < n; i ++) {
        auto it = lower_bound(ed.begin(), ed.end(), a[i][1]);
        if(it == ed.end()) {
            ed.emplace_back(a[i][1]);
        } else {
            int pos = it - ed.begin();
            ed[pos] = a[i][1];
        }
    }

    cout << ed.size() << '\n';
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
