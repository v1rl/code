#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
维护最高点和最低点作为比对区间[l,r]
*/

void solve() {
    int n, h;
    cin >> n >> h;
    i64 l = h, r = h;
    int cur = 0;
    bool f = true;
    for(int i = 0; i < n; i ++) {
        i64 t, x, y;
        cin >> t >> x >> y;
        int d = t - cur;
        r = min(r + d, y);
        l = max(l - d, x);
        if(!(r >= x && l <= y)) {
            f = false;
        }
        cur = t;
    }

    cout << (f ? "Yes" : "No") << '\n';
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
