#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        int n, k;
        cin >> n >> k;
        i64 res = 1ll * (n + n - k + 1) * k / 2;
        if(res & 1) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
}