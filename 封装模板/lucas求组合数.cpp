#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Lucas
{
    int n, mod;
    vector<int> fact;
    vector<int> infact;

    Lucas(int n_)
    {
        init(n_);
    }

    void init(int n_)
    {
        n = mod = n_;
        infact.resize(n + 1);
        fact.resize(n + 1);

        fact[0] = infact[0] = fact[1] = infact[1] = 1;
        for(int i = 2; i <= n; i ++) 
        {
            fact[i] = 1ll * fact[i - 1] * i % mod;
            infact[i] = 1ll * (mod - mod / i) * infact[mod % i] % mod;
        }
        for(int i = 2; i <= n; i ++) infact[i] = 1ll * infact[i - 1] * infact[i] % mod;
    }

    i64 C(i64 a, i64 b)
    {
        if(a < b) return 0;
        if(a < mod) return 1ll * fact[a] * infact[b] % mod * infact[a - b] % mod;
        return C(a / mod, b / mod) * C(a % mod, b % mod) % mod;
    }
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        i64 a, b;
        int mod;
        cin >> a >> b >> mod;
        Lucas lucas(mod);
        cout << lucas.C(a + b, b) << '\n';
    }
}