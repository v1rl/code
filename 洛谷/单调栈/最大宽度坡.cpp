#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

// https://leetcode.cn/problems/largest-rectangle-in-histogram/description/

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    vector<int> stk;
    for(int i = 0; i < n; i ++) {
        while(!stk.empty() && a[stk.back()] <= a[i]) {
            stk.pop_back();
        }
        stk.push_back(i);
    }

    /*
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        int l = -1, r = stk.size() - 1;
        while(l < r) {
            int mid = l + r + 1 >> 1;
            if(a[stk[mid]] >= a[i]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if(l != -1) {
            ans = max(ans, stk[l] - i);
        }
    }
    cout << ans << '\n';
    */

    int ans = 0;
    reverse(stk.begin(), stk.end());
    for(int i = 0; i < n; i ++) {
        while(!stk.empty() && a[i] <= a[stk.back()]) {
            ans = max(ans, stk.back() - i);
            stk.pop_back();
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
