#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/longest-increasing-subsequence/description/

/*
*/

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    vector<int> ed;
    for(int i = 0; i < n; i ++) {
        auto it = lower_bound(ed.begin(), ed.end(), a[i]);
        if(it == ed.end()) {
            ed.emplace_back(a[i]);
        } else {
            int pos = it - ed.begin();
            ed[pos] = a[i];
        }
    }

    cout << ed.size() << '\n';
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
