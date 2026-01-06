#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
关键词：离散化，线性dp；容斥原理转义，不下降子序列；前缀和，反直觉的不重不漏

显然，每个数可能出现的修改只有可能是在数组中出现过的数
但是值域比较大，要作为数据存在dp数组中需要先做一次离散化
维护f[i][j]表示当前维护到i且a[i]的值变成j的满足合法的最小花费
转移时，我们总是由前一个数(f[i - 1])且末尾(j)比它小的情况转移过来，我们需要遍历取最小的情况
这显然有重复，我们可以预处理对于(f[i - 1][])的前缀最小值，后续即可O(1)转移
初始化时，我们将数组初始化为最大值，f[0][0]初始化为0

实践表明，f不做空间优化会爆掉，因此使用了滚动数组优化
*/

const i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> kth;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        kth.emplace_back(a[i]);
    }
    vector<int> w(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> w[i];
    }

    sort(kth.begin(), kth.end());
    kth.erase(unique(kth.begin(), kth.end()), kth.end());

    auto rk = [&](int x) {
        return lower_bound(kth.begin(), kth.end(), x) - kth.begin();
    };

    vector<vector<i64>> f(2, vector<i64>(n + 1, inf));
    f[0][0] = 0;
    for(int i = 1; i <= n; i ++) {
        int cur = (i & 1);
        int rank = rk(a[i]);
        vector<i64> mn(kth.size(), inf);
        mn[0] = f[cur ^ 1][0];
        for(int j = 1; j < kth.size(); j ++) {
            mn[j] = min(mn[j - 1], f[cur ^ 1][j]);
        }
        for(int j = 0; j < kth.size(); j ++) {
            f[cur][j] = mn[j] + (j == rank ? 0 : w[i]);
        }
    }

    i64 ans = inf;
    for(int i = 0; i < kth.size(); i ++) {
        ans = min(f[n & 1][i], ans);
    }
    cout << ans << '\n';
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