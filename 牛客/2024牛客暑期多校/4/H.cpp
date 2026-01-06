#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 gcd(i64 a, i64 b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        cin >> n;
        vector<i64> dat(n);
        i64 ans = 0;
        for(int i = 0; i < n; i ++) 
        {
            cin >> dat[i];
        }
        sort(dat.begin(), dat.end());
        for(int i = 0; i < n - 1; i ++)
        {
            i64 x = dat[i + 1] - dat[i];
            
            ans = gcd(ans, x);
        }
        if(n == 1) ans = 0;
        cout << ans << '\n';
    }
}
