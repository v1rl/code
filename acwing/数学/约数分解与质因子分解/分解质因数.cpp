#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void divide(int x)
{
    for(int i = 2; i <= x / i; i ++)
    {
        if(x % i == 0)
        {
            int ans = 0;
            while(x % i == 0)
            {
                x /= i;
                ans ++;
            }
            cout << i << ' ' << ans << '\n';
        }
    }
    if(x > 1) cout << x << ' ' << 1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while(n --)
    {
        int x;
        cin >> x;
        divide(x);
    }
}