#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;
const int inf = 1e9;

// 一种类似快速幂的进制处理方式，这样就不必预处理每一位，而是用一次循环找到三进制下从低位到高位的数

void solve() {
    int n;
    cin >> n;

    int x = 0;
    i64 p = 1;
    i64 ans = 0;

    while(n) {
        ans += (n % 3) * (p * 3 + x * (p / 3));
        p *= 3;
        x ++;
        n /= 3;
    }

    cout << ans << '\n';
}


signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
}