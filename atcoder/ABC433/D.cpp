#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    unordered_map<int, int> mp[11];
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        int x = a[i];
        int cnt = 0;
        while(x) {
            cnt ++;
            x /= 10;
        }
        mp[cnt][a[i] % m] ++;
    }

    i64 ans = 0;
    for(int i = 0; i < n; i ++) {
        i64 x = a[i] % m;
        for(int j = 1; j <= 10; j ++) {
            x *= 10;
            x %= m;
            ans += mp[j][(m - x % m) % m];
        }
    }

    cout << ans << '\n';

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