#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

// 必然在前面的数、必然在后面的数

void solve()
{
    int n;
    cin >> n;
    int t;
    cin >> t;

    int s1 = 0, s2 = 0;
    for(int i = 1; i < n; i ++)
    {
        int x;
        cin >> x;
        if(abs(x) < abs(t)) s1 ++;
        if(-abs(x) > -abs(t)) s2 ++;
    }
    if(s1 < (n + 1) / 2 || s2 <= n / 2)
    {
        cout << "YES" << '\n';
    }
    else cout << "NO" << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --)
    {
        solve();
    }
    return 0;
}