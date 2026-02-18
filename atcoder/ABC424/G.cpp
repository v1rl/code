#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
容量约束问题下的代价最大化，不难联想到费用流
但本题是选子集问题，也就是离散的0/1选则（要么选b个人拿到c，要么啥也没有），不符合流的连续性
考虑将网络流判定条件代数化
注意到：行为演员可执行场次a，列为一场需要的演员数b，题目的网络流可行性判定可转化为已知行列和，求0-1矩阵存在性
可以转用 Gale-Ryser 定理解决
因为a可以有剩，无需判定总和相等，且我们以a作为供给侧，预处理出k~[1, m]的最大供给量
按照需求的从大到小排序
然后跑一个属性为最大价值的背包dp(当前处理到第几个，选择了几个，需求总和是多少）即可
*/

const i64 inf = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<array<int, 2>> b(m + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int s = 0;
    for(int i = 1; i <= m; i ++) {
        cin >> b[i][0] >> b[i][1];
        s += b[i][0];
    }
    sort(b.begin() + 1, b.end(), greater());

    vector dp(m + 1, vector(s + 1, -inf));
    vector<int> pre(m + 1);
    for(int i = 1; i <= m; i ++) {
        for(int j = 1; j <= n; j ++) {
            pre[i] += min(a[j], i);
        }
    }


    dp[0][0] = 0;
    for(int i = 1; i <= m; i ++) {
        for(int j = i; j >= 1; j --) {
            for(int k = s; k >= b[i][0]; k --) {
                if(k <= pre[j]) {
                    dp[j][k] = max(dp[j][k], dp[j - 1][k - b[i][0]] + b[i][1]);
                }
            }
        }
    }

    i64 ans = 0;
    for(int j = 0; j <= m; j ++) {
        for(int k = 0; k <= s; k ++) {
            ans = max(ans, dp[j][k]);
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