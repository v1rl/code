#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n, pos;
    cin >> n >> pos;

    vector<int> a(n + 1);
    int num0 = 0;
    int pre = 0, suf = 0;
    bool f = false;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if(a[i] == 1 && !f) {
            pre ++;
        } else {
            f = true;
        }

        if(a[i] == 1) {
            suf ++;
        } else {
            suf = 0;
        }

        if(a[i] == 0) {
            num0 ++;
        }
    }

    pre = min(pos, pre);
    suf = min(suf, n - pos);

    int ans = num0;
    if(pre != n) {
        ans += (n - num0 - pre - suf) * 2;
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