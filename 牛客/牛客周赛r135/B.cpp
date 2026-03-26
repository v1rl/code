#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        mp[x - i] ++;
    }

    int mx = 0;
    for(auto [_, y] : mp) {
        mx = max(mx, y);
    }
    cout << mx << '\n';
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
