#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
typedef pair<int, int> PII;

/*
*/

const i64 inf = 1e18 + 10;
const int mod = 998244353;

void solve() {
    int n, t;
    cin >> n >> t;

    map<int, int> mp;

    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        mp[x] ++;
    }

    int mx = 0;
    int cnt = 0;
    for(auto [x, c] : mp) {
        if(x == t) {
            cnt = c;
        }
        mx = max(mx, c);
    }

    cout << max(mx - cnt, 0) << '\n';
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
