#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
暴力为n^2的双指针，考虑优化，只暴力移动左边的分界点，思考移动过程中右边分界点的最优位置会发生什么变化
注意到：集合元素全部减去同一个值不会影响最值归属
但是，在移动过程中，集合中元素也被删去了，不过这样的删除是线性从左往右的
不难想到，只需要维护后缀最大即可
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }    
    for(int i = 1; i <= n; i ++) {
        cin >> b[i];
    }    
    for(int i = 1; i <= n; i ++) {
        cin >> c[i];
    }    
    vector<i64> preb(n + 1), prea(n + 1), sufc(n + 2);
    for(int i = 1; i <= n; i ++) {
        prea[i] += prea[i - 1] + a[i];
        preb[i] += preb[i - 1] + b[i];
    }
    for(int i = n; i >= 1; i --) {
        sufc[i] += sufc[i + 1] + c[i];
    }

    vector<i64> mx(n + 1, 0);
    for(int i = n - 1; i >= 1; i --) {
        mx[i] = max(mx[i + 1], preb[i] + sufc[i + 1]);
    }

    i64 ans = 0;
    for(int i = 1; i <= n - 2; i ++) {
        ans = max(ans, prea[i] + mx[i + 1] - preb[i]);
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
