#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int exgcd(i64 a, i64 b, int &x, int &y)
{
    if(!b)
    {
        x = 1, y = 0;
        return a;
    }
    int g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), m(n);
    i64 M = 1;
    for(int i = 0; i < n; i ++)
    {
        cin >> m[i] >> a[i];
        M *= m[i];
    }

    i64 ans = 0;
    for(int i = 0; i < n; i ++)
    {
        i64 Mi = M / m[i];
        int ti, y;
        exgcd(Mi, m[i], ti, y);
        ans += a[i] * Mi * ti;
    }
    
    cout << (ans % M + M) % M << '\n';
}