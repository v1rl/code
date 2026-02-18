#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n, q;
    cin >> n >> q;
    vector<i64> pre(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> pre[i];
        pre[i] += pre[i - 1];
    }

    int p = 0;
    while(q --) {
        int op;
        cin >> op;
        if(op == 1) {
            int c;
            cin >> c;
            p += c;
            p %= n;
        } else {
            int l, r;
            cin >> l >> r;
            l += p, r += p;
            l = (l - 1) % n + 1;
            r = (r - 1) % n + 1;
            if(l <= r) {
                cout << pre[r] - pre[l - 1] << '\n';
            } else {
                cout << pre[n] - pre[l - 1] + pre[r] << '\n';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(15);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}