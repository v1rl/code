#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> d;
    for(int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        d.push_back({x, y});
    }

    sort(d.begin(), d.end(), 
        [&](auto x, auto y) {
            if(x[0] == y[0]) {
                return x[1] > y[1];
            }
            return x[0] < y[0];
        });

    vector<int> g;
    for(auto [_, y] : d) {
        auto pos = lower_bound(g.begin(), g.end(), y);
        if(pos == g.end()) {
            g.emplace_back(y);
        } else {
            *pos = y;
        }
    }

    cout << g.size() << '\n';
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