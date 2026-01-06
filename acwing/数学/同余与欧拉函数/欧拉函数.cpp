#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while(n --)
    {
        int x;
        cin >> x;
        i64 ans = x;
        for(int i = 2; i <= x / i; i ++)
        {
            if(x % i == 0)
            {
                while(x % i == 0)
                {
                    x /= i;
                }
                ans = ans * (i - 1) / i;
            }
        }
        if(x > 1) ans = ans * (x - 1) / x;

        cout << ans << '\n';
    }
}