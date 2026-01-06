#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;
/*

*/

void solve() {
    int n;
    cin >> n;
    int res = 0;
    int cnt = 0;
    int mx = -inf;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        if(x < 0) {
            mx = max(mx, x);
            cnt ++;
        } else if(x == 0) {
            res ++;
        }
    }
    if(cnt & 1) {
        res += 1 - mx;
    }
    cout << res << '\n';
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