#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

const int mod = 998244353;
const int inf = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        mp[x ^ i] ++;
    }

    int mx = 0;
    for(auto [x, c] : mp) {
        mx = max(mx, c);
    }

    cout << n - mx << '\n';
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