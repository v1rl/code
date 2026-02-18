#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int pre = 0, suf = 0;
    bool f = false;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(a[i] == 0 && !f) {
            pre ++;
        } else {
            f = true;
        }

        if(a[i] == 0) {
            suf ++;
        } else {
            suf = 0;
        }
    }

    if(pre == n) {
        cout << 0 << '\n';
    } else {
        cout << n - 1 - pre - suf << '\n';
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