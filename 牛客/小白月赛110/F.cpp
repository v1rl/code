#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
int mod;

i64 qmi(i64 a, i64 b)
{
    i64 res = 1;
    while(b)
    {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n, r;
    cin >> n >> mod >> r;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
        cin >> a[i];

    if(r == 0)
    {
        for(int i = 1; i <= n; i ++)
        {
            if(a[i] == 0) a[i] = 1;
        }
    }
    else
    {
        unordered_set<int> S;
        S.insert(1);
        int invx = qmi(r, mod - 2);
        int pre = 1;
        for(int i = 1; i <= n; i ++)
        {
            if(a[i] == 0)
            {
                S.clear();
                S.insert(1);
                pre = 1;
                continue;
            }
            pre = 1ll * pre * a[i] % mod;
            if(S.count(1ll * pre * invx % mod))
            {
                a[i] = 0;
                S.clear();
                S.insert(1);
                pre = 1;
            }
            else S.insert(pre);
        }
    }

    for(int i = 1; i <= n; i ++)
    {
        cout << a[i] << ' ';
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    t = 1;
    // cin >> t;
    while(t --)
    {
        solve();
    }
}