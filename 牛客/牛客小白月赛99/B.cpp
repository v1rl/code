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
        i64 x;
        cin >> x;
        int ans = 0;
        while(x)
        {
            x %= (x / 2 + 1);
            ans ++;
        }
        cout << ans << '\n';
    }
}