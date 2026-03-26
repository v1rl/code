#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/tJau2o/description/

/*
*/

const int mod = 1e9 + 7;

void solve() {

    /*
    // 偏移量dp
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    vector f(2, vector(2001, 0));
    f[0][1000] = 1;

    for(int i = 1; i <= n; i ++) {
        int cur = i & 1;
        for(int j = 0; j <= 2000; j ++) {
            // 注意滚动数组的清零操作
            f[cur][j] = 0;
            if(j - a[i] >= 0 && j - a[i] <= 2000) {
                f[cur][j] += f[cur ^ 1][j - a[i]];
            }
            if(j + a[i] >= 0 && j + a[i] <= 2000) {
                f[cur][j] += f[cur ^ 1][j + a[i]];
            }
        }
    }

    cout << f[n & 1][m + 1000];
    */

    // 等价背包
    int n, m;
    cin >> n >> m;
    int sum = 0;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum += a[i];
        a[i] *= 2;
    }

    m += sum;
    if(m < 0) {
        cout << 0 << '\n';
        return;
    }

    vector<int> f(m + 1);
    f[0] = 1;
    for(int i = 1; i <= n; i ++) {
        for(int j = m; j >= a[i]; j --) {
            f[j] += f[j - a[i]];
        }
    }

    cout << f[m] << '\n';
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
