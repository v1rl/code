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
        for(int i = 0; i < n; i ++) cin >> a[i];
        if(n == 1 || n == 2)
        {
            cout << -1 << '\n';
            continue;
        }
        sort(a.begin(), a.end());
        i64 sum = accumulate(a.begin(), a.end(), 0ll);
        i64 ans = max(0ll, a[n / 2] * 2ll * n - sum + 1);
        cout << ans << '\n';
    }
}