#include<bits/stdc++.h> 
using namespace std;   
using i64 = long long;

int exgcd(int a, int b, i64 &x, i64 &y)
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
    int a, b, m, n, l;
    cin >> a >> b >> m >> n >> l;
    i64 x, y;
    int g = exgcd(m - n, l, x, y);
    if((b - a) % g) cout << "Impossible" << '\n';
    else
    {
        x *= (b - a) / g;
        int t = abs(l / g);
        cout << (x % t + t) % t << '\n';
    }
}  
