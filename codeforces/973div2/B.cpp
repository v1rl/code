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
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n, 1e9);
        for(int i = 0; i < n; i ++) cin >> a[i];

        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
            {
                if(j == i) continue;
                b[i] = min(b[i], gcd(a[i], a[j]));
            }

        i64 ans = 1e18;
        for(int i = 0; i < n; i ++)
        {
            ans = min(ans, 1ll * a[i] + b[i] * (n - 1));
        }

        cout << ans << '\n';
    }
}