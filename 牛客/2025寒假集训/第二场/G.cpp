#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
单步扩张O(logn)
单步扩张后的维护量更新O(n)

CDQ分治
双集合合并O(n)
双集合合并后的维护量更新O(n)

通过分治的同时存储跨区间询问，本题可以扩展到询问任意区间
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector<i64> ans(n + 1), val(n + 1);
    vector<int> p(n + 1), q(n + 1), tmp(n + 1);
    auto cdq = [&](auto &&self, int l, int r) {
        if(l == r) {
            ans[l] = val[l] = a[l];
            p[l] = q[l] = l;
            return;
        }

        int mid = l + r >> 1;
        self(self, l, mid);
        self(self, mid + 1, r);

        i64 pre = 0;
        for(int i = l, j = mid + 1; i <= mid; i ++) {
            while(j <= r && ans[p[i]] >= val[q[j]]) {
                pre += a[q[j]];
                j ++;
            }
            ans[p[i]] += pre;
        }

        int i = l, j = mid + 1, k = l;
        i64 lv = 0;
        i64 lst = 0;
        while(i <= mid || j <= r) {
            if(i <= mid && (j == r + 1 || val[q[i]] < val[q[j]] - lv)) {
                lst = val[q[i]];
                lv += a[q[i]];
                tmp[k ++] = q[i];
                i ++;
            } else {
                lst = max(lst, val[q[j]] - lv);
                val[q[j]] = lst;
                tmp[k ++] = q[j];
                j ++;
            }
        }

        copy(tmp.begin() + l, tmp.begin() + r + 1, q.begin() + l);
        inplace_merge(p.begin() + l, p.begin() + mid + 1, p.begin() + r + 1, 
            [&](int x, int y) {
                return ans[x] < ans[y];
            });
    };

    cdq(cdq, 1, n);
    for(int i = 1; i <= n; i ++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}