#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7;

// 用短距离凑出的最终距离在一个范围内 ———— max(0, mx * 2 - sum) <= d <= sum

void solve()
{
    int n;
    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    i64 sum = 0;
    i64 mx = 0;
    for(int i = 1; i <= n; i ++) {
        i64 x;
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }
    i64 p = 1ll * (x1 - x2) * (x1 - x2) + 1ll * (y1 - y2) * (y1 - y2);
    i64 l = max(0ll, mx * 2 - sum);
    if(l * l <= p && p <= sum * sum) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
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