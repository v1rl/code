#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int exgcd(int a, int b, int &x, int &y)
{
    if(!b)
    {
        x = 1, y = 0;
        return a;
    }
    int t = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return t;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        int a, b, m;
        cin >> a >> b >> m;
        int x, y;
        int t = exgcd(a, m, x, y);
        if(b % t) cout << "impossible" << '\n';
        else cout << x * b / t << '\n';
    }
    return 0;
}