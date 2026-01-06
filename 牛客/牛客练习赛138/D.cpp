#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 lcm(i64 a, i64 b)
{
    return a * b / gcd(a, b);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(18);
    for(int i = 1; i <= 16; i ++)
        a[i] = (1 << i) - 1;
    
    for(int i = 1; i <= n; i ++)
    {
        string s;
        cin >> s;
        int t = 0;
        int p = 1;
        int l = s.size();
        for(int j = 0; j < l; j ++)
        {
            if(s[j] == '1')
                t += p;
            p *= 2;
        }
        a[l] &= t;
    }

    int h = 1;
    for(int i = 2; i <= 16; i ++)
        h = lcm(h, i);

    for(int i = 1; i <= h; i ++)
    {
        bool f = true;
        for(int j = 1; j <= 16; j ++)
            if(!((a[j] >> ((i - 1) % j)) & 1)) 
                f = false;
        if(f)
        {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --)
    {
        solve();
    }
    return 0;
}