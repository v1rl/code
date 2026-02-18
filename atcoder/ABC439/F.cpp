#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
题意可转换为极大值个数严格大于极小值个数
注意到：极大值和极小值并非独立，而是相互依存的，不会存在连续两个极值都是极大值或极小值的情况
所以，极大值和极小值的数量差最多为1
要让极大值个数可能大于极小值个数，第一个极值和最后一个极值都必须为极大值
则一定有a[1]>a[0]且a[k-1]>a[k]
因为本题是对子序列的选取，所以不能通过考虑相邻数的大小关系执行统计
注意到：固定a[1]和a[k-1]，找a[1]左边比它小的个数p和a[k-1]右边比它大的个数q的维护方案，可以不重不漏地完成统计
但此时我们需要遍历两个指针，显然是需要进一步优化的
注意到：我们可以维护一个指针的全体操作集，且维护*和+的纯增操作集显然要好于维护/和-的纯删操作集
于是我们从左到右维护sum表示当前左指针（包括2的次幂部分）的所有贡献
*/

const int mod = 998244353;

struct Fenwick {
    int n;
    vector<int> a;

    Fenwick(int n_) : n(n_), a(n + 1) {};

    void add(int x, const int &v) {
        for(int i = x; i <= n; i += i & -i) {
            a[i] += v;
        }
    }

    int sum(int x) {
        int res = 0;
        for(int i = x; i; i -= i & -i) {
            res += a[i];
        }
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    Fenwick tr1(n), tr2(n);

    vector<int> pre(n), suf(n);
    for(int i = 0; i < n; i ++) {
        pre[i] = tr1.sum(a[i]);
        tr1.add(a[i], 1);
    }
    for(int i = n - 1; i >= 0; i --) {
        suf[i] = tr2.sum(a[i]);
        tr2.add(a[i], 1);
    }

    // 需要注意，本题还有长度为3的、a[1]和a[k-1]为同一个数的特殊情况，需要单独累计
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        ans += 1ll * pre[i] * suf[i] % mod;
        ans %= mod; 
    }

    i64 sum = 0;
    for(int i = 1; i < n; i ++) {
        ans += sum * suf[i] % mod;
        ans %= mod;
        sum = sum * 2 + pre[i];
        sum %= mod;
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