#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 2e4 + 10;
const int inf = 1e9;

/*
前 i 个数异或和为 j 的最大长度
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector f(n + 1, vector(N + 1, -inf));
    f[0][0] = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < N; j ++) {
            // 注意位运算符的括号
            if((j ^ a[i]) > N) {
                continue;
            }
            f[i][j] = max(f[i - 1][j], f[i - 1][j ^ a[i]] + 1);
        }
    }

    if(f[n][m] < 0) {
        cout << -1 << '\n';
    } else {
        cout << n - f[n][m] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t --) {
        solve();
    }
    return 0;
}