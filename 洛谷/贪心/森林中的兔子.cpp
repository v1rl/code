#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://leetcode.cn/problems/rabbits-in-forest/description/

void solve() {
    int n;
    cin >> n;
    vector<int> a(1002);
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        a[x + 1] ++;
    }

    int ans = 0;
    for(int i = 1; i <= 1001; i ++) {
        int t = (a[i] + i - 1) / i;
        ans += t * i;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}