#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/minimum-operations-to-make-the-array-k-increasing/description/

/*
*/

const int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 0; i < k; i ++) {
        vector<int> ed;
        int cnt = 0;
        for(int j = i; j < n; j += k) {
            cnt ++;
            auto it = upper_bound(ed.begin(), ed.end(), a[j]);
            if(it == ed.end()) {
                ed.emplace_back(a[j]);
            } else {
                int pos = it - ed.begin();
                ed[pos] = a[j];
            }
        }
        ans += cnt - ed.size();
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
