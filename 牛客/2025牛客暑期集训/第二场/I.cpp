#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// 读明白题

void solve() {
    int a, b;
    cin >> a >> b;
    if(a != 1 && b != 1) {
        cout << 1 << '\n';
    } else {
        cout << -1 << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --)
    {
        solve();
    }
}