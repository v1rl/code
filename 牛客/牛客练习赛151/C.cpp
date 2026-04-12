#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int mod = 998244353;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }


    i64 pos = 1e18;

    auto b = a;
    int mx = *max_element(b.begin(), b.end());
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i ++) {
        if(a[i] != b[i]) {
            pos = min(pos, 1ll * a[i] * mx);
        }
    }

    while(q --) {
        i64 x;
        cin >> x;
        cout << (x <= pos ? "Yes" : "No") << '\n';
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
