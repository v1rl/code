#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
对阶乘跑质因子分解可行，但过于慢了
用数学公式转换，去掉公式中的阶乘
*/

const int N = 5010;
int C[N][N];
int mod;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        sum += a[i];
    }

    i64 ans = 1;
    for(int i = 0; i < n; i ++) {
        ans = (ans * C[sum][a[i]]) % mod;
        sum -= a[i];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t >> mod;
    for(int i = 0; i <= 5000; i ++) {
        C[i][0] = 1;
        for(int j = 1; j <= i; j ++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }

    while(t --) {
        solve();
    }
    return 0;
}