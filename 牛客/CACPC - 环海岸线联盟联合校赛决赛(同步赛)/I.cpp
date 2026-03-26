#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7;

const int N = 1e5 + 10;
int f[N][2][2];

void solve() {
    int n;
    cin >> n;
    if(n == 1) {
        cout << 2 << '\n';
    } else {
        cout << (((f[n][1][0] + f[n][0][1]) % mod) + f[n][1][1]) % mod << '\n';
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    f[2][0][1] = f[2][1][1] = f[2][1][0] = 1;

    for(int i = 3; i <= 100000; i ++) {
        f[i][0][1] = f[i - 1][1][0];
        f[i][1][1] = f[i - 1][0][1];
        f[i][1][0] = (f[i - 1][1][1] + f[i - 1][0][1]) % mod;

    }

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
