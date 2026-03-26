#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://www.luogu.com.cn/problem/P8776

/*
*/

const int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector<int> suf(n + 1);
    vector<int> ed;
    for(int i = n; i >= 1; i --) {
        auto it = upper_bound(ed.begin(), ed.end(), a[i], greater());
        if(it == ed.end()) {
            ed.emplace_back(a[i]);
            suf[i] = ed.size();
        } else {
            int pos = it - ed.begin();
            ed[pos] = a[i];
            suf[i] = pos + 1;
        }
    }

    ed.clear();
    
    int ans = 0;
    for(int l = 1, r = k + 1; r <= n; l ++, r ++) {
        auto it = upper_bound(ed.begin(), ed.end(), a[r]);
        int res = it - ed.begin();
        ans = max(ans, res + suf[r] + k);
        it = upper_bound(ed.begin(), ed.end(), a[l]);
        if(it == ed.end()) {
            ed.emplace_back(a[l]);
        } else {
            int pos = it - ed.begin();
            ed[pos] = a[l];
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
