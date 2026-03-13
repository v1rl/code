#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://leetcode.cn/problems/minimize-deviation-in-array/description/

void solve() {
    int n;
    cin >> n;
    set<int> S;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        if(x & 1) {
            S.insert(x * 2);
        } else {
            S.insert(x);
        }
    }

    int ans = *S.rbegin() - *S.begin();
    while(*S.rbegin() % 2 == 0) {
        int t = *S.rbegin();
        S.erase(t);
        S.insert(t / 2);
        ans = min(ans, *S.rbegin() - *S.begin());
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