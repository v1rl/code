#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
维护f[i]表示当前以i结尾且a[i]不做修改的最小花费

转移时，j ~ [1, i - 1]中所有a[j] <= a[i]的，价值为f[j] + w[j + 1 ~ i - 1]
在维护答案时，对每个f[i]，剩余部分全部修改，遍历得到这样的最小花费

Trick:  最终答案不一定非得直接是f[n]，dp数组也不一定非得维护最终答案，最终答案可能会由f[1~n]取最优表示
        因此dp数组维护的属性可以更发散，在最终答案能够被不重不漏的表示的情况下发散想象     
*/
const i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), w(n + 1);
    vector<i64> pre(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++) {
        cin >> w[i];
        pre[i] = pre[i - 1] + w[i];
    }

    vector<i64> f(n + 1, inf);
    f[0] = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < i; j ++) {
            if(a[j] <= a[i]) {
                f[i] = min(f[i], f[j] + pre[i - 1] - pre[j]);
            }
        }
    }

    i64 ans = inf;
    for(int i = 1; i <= n; i ++) {
        ans = min(ans, f[i] + pre[n] - pre[i]);
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