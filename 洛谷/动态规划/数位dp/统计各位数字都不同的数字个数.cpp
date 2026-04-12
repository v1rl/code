#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/count-numbers-with-unique-digits/description/

/*
*/

const int inf = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    if(n == 0) {
        cout << 1 << '\n';
    } else if(n == 1) {
        cout << 10 << '\n';
    } else {
        int ans = 10;
        int res = 9;
        for(int i = 2, j = 9; i <= n; i ++, j --) {
            res *= j;
            ans += res;
        }
        cout << ans << '\n';
    }
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
