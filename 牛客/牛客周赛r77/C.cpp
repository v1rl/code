#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
 
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        i64 x, y, a, b, c, d;
        cin >> x >> y >> a >> b >> c >> d;
        i64 t = __gcd(a, b);
        i64 p = __gcd(c, d);
        swap(x, y);
 
        if(x % t || y % p) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
}