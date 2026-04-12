#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://www.nowcoder.com/practice/3473e545d6924077a4f7cbc850408ade

/*
*/

const int inf = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    /*
    // 单调队列+二分
    vector<int> a(n), pre(n + 1);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
    }

    vector<int> g;
    g.emplace_back(0);
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        int l = 0, r = g.size();
        int x = pre[i] - k;
        while(l < r) {
            int mid = l + r >> 1;
            if(pre[g[mid]] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if(l != g.size()) {
            ans = max(ans, i - g[l]); 
        }

        if(pre[i] > pre[g.back()]) {
            g.emplace_back(i);
        }
    }   
    cout << ans << '\n';
    */

    // 贪心预处理+双指针
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    vector<int> rmn(n), rpos(n);
    rmn[n - 1] = a[n - 1], rpos[n - 1] = n;
    for(int i = n - 2; i >= 0; i --) {
        rmn[i] = a[i];
        rpos[i] = i + 1;
        if(rmn[i + 1] <= 0) {
            rmn[i] += rmn[i + 1];
            rpos[i] = rpos[i + 1];
        }
    }

    int res = 0;
    int ans = 0;
    for(int l = 0, r = 0; l < n; l ++) {
        while(r < n && res + rmn[r] <= k) {
            res += rmn[r];
            r = rpos[r];
        }
        if(r > l) {
            ans = max(ans, r - l);
            res -= a[l];
        } else {
            r ++;
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
