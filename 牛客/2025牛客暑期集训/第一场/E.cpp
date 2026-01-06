#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

// 打表找规律

void solve() {
    int ans[5] = {3, 5, 7, 8, 9};
    i64 a, b;
    cin >> a >> b;
    i64 res = abs(a * a - b * b);
    for(int i = 0; i <= 4; i ++) {
        if(res == ans[i]) {
            cout << i + 1 << '\n';
            return;
        }
    }

    res -= 10;
    int p = res % 4;
    res /= 4;
    i64 anss = res * 3 + 5 + p;
    cout << anss << '\n';
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