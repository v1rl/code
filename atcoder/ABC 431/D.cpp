#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
选到第i个且头部选的重量为j的最大值
初始化，全体为负无穷，然后f[0][0]为0
额外维护前i个的重量总和sum

降维后，从后往前维护即可
*/

const i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1), a(n + 1), b(n + 1);
    int sum = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> w[i] >> a[i] >> b[i];
        sum += w[i];
    }

    vector<i64> f(sum + 1, -inf);

    sum = 0;
    f[0] = 0;
    for(int i = 1; i <= n; i ++) {
        sum += w[i];
        for(int j = sum; j >= 0; j --) {
            f[j] = f[j] + b[i];
            if(j >= w[i]) {
                // 需要注意，在维护的中途我们是暂时允许头部重量大于身体重量的
                f[j] = max(f[j], f[j - w[i]] + a[i]);
            } 
        }
    }

    i64 ans = -inf;
    for(int j = 0; j <= sum; j ++) {
        if(j <= sum - j) {
            ans = max(ans, f[j]);
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