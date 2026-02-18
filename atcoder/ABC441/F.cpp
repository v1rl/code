#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
题目需要知道单点对整个背包的贡献度
暴力做法是考虑得到所有背包路径，根据点的出现次数判断，显然会超时，而且有些小题大做了
转换思路，想知道一个物品对整体的影响，则考虑 必选和必不选它 对整体的影响（这一点类似组合数公式中的C(n, m)=C(n-1,m)+C(n-1,m-1)）
即考虑对该点特殊处理后剩余部分的dp
暴力显然不可取，注意到dp无后效性，我们可以用预处理前后缀后，统一它们，得到目标"剩余部分"
统一的具体操作，即枚举前缀和后缀分别占据多少背包容量
之后分类讨论必选和必不选情况下的最优解变化即可得到答案
*/

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n + 1), w(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> v[i] >> w[i];
    }

    vector pf(n + 1, vector(m + 1, 0ll));
    vector sf(n + 2, vector(m + 1, 0ll));

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            pf[i][j] = pf[i - 1][j];
            if(j >= v[i]) {
                pf[i][j] = max(pf[i][j], pf[i - 1][j - v[i]] + w[i]);
            }
        }
    }

    for(int i = n; i >= 1; i --) {
        for(int j = 1; j <= m; j ++) {
            sf[i][j] = sf[i + 1][j];
            if(j >= v[i]) {
                sf[i][j] = max(sf[i][j], sf[i + 1][j - v[i]] + w[i]);
            }
        }
    }

    i64 ans = pf[n][m];

    for(int i = 1; i <= n; i ++) {
        i64 res = 0;
        for(int j = 0; j <= m; j ++) {
            res = max(res, pf[i - 1][j] + sf[i + 1][m - j]);
        }
        if(res < ans) {
            cout << 'A';
            continue;
        }

        res = 0;
        for(int j = 0; j <= m - v[i]; j ++) {
            res = max(res, pf[i - 1][j] + sf[i + 1][m - v[i] - j]);
        }
        if(res == ans - w[i]) {
            cout << 'B';
        } else {
            cout << 'C';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(15);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}