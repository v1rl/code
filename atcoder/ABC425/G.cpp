#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
位运算的最值问题，高位决定权大于低位，考虑从高位向低位贪心
单点的查询可以对A建Trie树后直接树上搜索完成
但需要查询的数很多，无法暴力执行，注意查询区间是一个连续区间[0,m-1]，考虑能否将一系列区间等价并一起计算
注意到：询问结构[0, M-1]可以拆分为 O(logM) 个"二进制对齐"的完整区间（类似线段树拆分区间）
        而 Trie 树的每个节点恰好也是管理一个"二进制对齐"的数值区间，询问结构与数据结构是同构的，因此可以同步递归
所以，考虑按位分治，结合Trie树的思想维护可选集的0/1，从高位到低位跑一个类似数位dp的分治递归
跑递归时，要按照Trie树的模式，在可选集中某一侧（0/1）不存在数时，剪断那一位所在分支
整体的解空间极大，但Trie树用到的解空间是较小的，相应的按照Trie树的模式跑按位分治的解空间也是较小的
calc(当前状态的可选集b, 当前x在低k位的取值范围是[0, m-1], 当前正处理的最高位下标k（权重2^k）)
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    auto calc = [&](auto &&self, vector<int> &b, int u, int k) -> i64 {
        if(k == -1) {
            return 0;
        }
        vector<int> b0, b1;
        i64 bit = (1 << k);
        int S = b.size();

        for(int i = 0; i < S; i ++) {
            if(b[i] & bit) {
                b1.emplace_back(b[i]);
            } else {
                b0.emplace_back(b[i]);
            }
        }

        i64 mid = bit;

        i64 res = 0;
        if(u == (1 << (k + 1))) {
            if(b0.empty()) {
                // 需要注意，这里用乘法，而不能跑两次相同的递归
                res = mid * mid + 2 * self(self, b1, mid, k - 1);
            } else if(b1.empty()) {
                res = mid * mid + 2 * self(self, b0, mid, k - 1);
            } else {
                res = self(self, b0, mid, k - 1) + self(self, b1, mid, k - 1);
            }
        } else {
            i64 len1 = min<i64>(mid, u);
            if(b0.size()) {
                res += self(self, b0, len1, k - 1);
            } else {
                res += mid * len1 + self(self, b1, len1, k - 1);
            }
            i64 len2 = u - mid;
            if(len2 > 0) {
                if(b1.size()) {
                    res += self(self, b1, len2, k - 1);
                } else {
                    res += mid * len2 + self(self, b0, len2, k - 1);
                }
            }
        }
        return res;
    };

    // 1e9情况下最高位的1就是第29位的1
    cout << calc(calc, a, m, 29) << '\n';
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