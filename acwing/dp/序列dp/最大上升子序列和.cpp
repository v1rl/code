#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    vector<int> f(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        f[i] = a[i];
        for(int j = 1; j < i; j ++)
        {
            if(a[j] < a[i]) f[i] = max(f[i], f[j] + a[i]);
        }
    }
    int mx = 0;
    for(int i = 1; i <= n; i ++)
    {
        mx = max(mx, f[i]);
    }

    cout << mx << '\n';
}