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
        i64 a, b, c, d;
        cin >> a >> b >> c >> d;
        i64 ans = a * min(c, d) + b * d;
        cout << ans << '\n';
    }
}