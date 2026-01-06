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
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while(n --)
    {
        int a, b;
        cin >> a >> b;
        int x, y;
        exgcd(a, b, x, y);
        cout << x << ' ' << y << '\n';
    }
}