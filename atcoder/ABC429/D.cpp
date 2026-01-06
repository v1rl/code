#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
关键词：贪心，二分，前缀和，离散化，区间优化

不难想到对m范围的每个点做一次二分，即可得到以当前点开始能路过的人数
m的值很大，显然需要考虑优化
不难发现，连续的那些没有人站的点构成的区间总会得到相同的结果，而影响结果的因素便是当前点所能遇到的第一个站人的点是什么
因此，我们可以只对那些站了人的点做二分，中间的无人点直接得到答案

点数较小，但点的范围很大，于是我们需要先做离散化
二分统计人数时，我们需要用到前缀和，破环成链

另外，需要额外加入点m以避免最后一段被漏掉
*/

void solve() {
    int n, k;
    i64 m;
    cin >> n >> m >> k;

    vector<i64> a(n);
    vector<i64> kth;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        kth.emplace_back(a[i]);
    }
    kth.emplace_back(m);
    sort(kth.begin(), kth.end());
    kth.erase(unique(kth.begin(), kth.end()), kth.end());

    auto rk = [&](i64 x) {
        return lower_bound(kth.begin(), kth.end(), x) - kth.begin();
    };

    vector<int> st(kth.size() * 2);
    for(int i = 0; i < n; i ++) {
        st[rk(a[i])] ++;
    }

    for(int i = kth.size(); i < 2 * kth.size(); i ++) {
        st[i] = st[i - kth.size()];
    }

    vector<i64> pre(kth.size() * 2 + 1);
    for(int i = 1; i <= kth.size() * 2; i ++) {
        pre[i] = pre[i - 1] + st[i - 1];
    }

    auto range = [&](int l, int r) {
        return pre[r + 1] - pre[l];
    };

    i64 lst = 0;
    i64 ans = 0;
    for(int i = 0; i < kth.size(); i ++) {
        int l = i, r = kth.size() * 2 - 1;
        while(l < r) {
            int mid = l + r >> 1;
            if(range(i, mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        i64 p = range(i, l);
        ans += p * (kth[i] - lst);
        lst = kth[i];
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
