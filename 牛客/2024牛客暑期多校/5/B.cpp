#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    bool f = false;
    if((n * m) & 1) f = false;
    else
    {
        if(a == 1 && b == 1) f = true;
        else if(a == 0 && b == 0)
        {
            if(n * m == 2) f = true;
            else f = false;
        }
        else if(a == 1 && b == 0)
        {
            if(n == 1 || m == 1) f = true;
            else f = false;
        }
        else if(a == 0 && b == 1)
        {
            if((n == 1 && m > 2) || (m == 1 && n > 2)) f = false;
            else f = true;
        }
    }
    if(f) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        solve();
    }
}