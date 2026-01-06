#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7;

// 数据小时可以考虑用while写暴力

void solve()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if(a > b) {
        if(b == (a ^ 1)) {
            cout << y << '\n';
        } else {
            cout << -1 << '\n';
        }
        return;
    }

    int t = (b - a) / 2;
    if((b - a) & 1) {
        if(a & 1) {
            cout << (t + 1) * x + min(x, y) * t << '\n';
        } else {
            cout << t * x + min(x, y) * (t + 1) << '\n';
        }
    } else {
        cout << t * x + t * min(x, y) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --)
    {
        solve();
    }
}