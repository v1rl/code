#include<bits/stdc++.h> 
using namespace std;   
using i64 = long long;

vector<int> minp, primes;
void sieve(int n)
{
    minp.assign(n + 1, 0);
    for(int i = 2; i <= n; i ++)
    {
        if(!minp[i])
        {
            minp[i] = i;
            primes.emplace_back(i);
        }
        for(auto p : primes)
        {
            if(i * p > n) break;
            minp[i * p] = p;
            if(i % p == 0) break;
        }
    }
}

void solve()
{
    i64 a0, a1, b0, b1;
    cin >> a0 >> a1 >> b0 >> b1;
    vector<array<int, 2>> vec;
    int n = b1; 
    for(int i = 0; primes[i] <= n / primes[i]; i ++)
    {
        if(n % primes[i] == 0)
        {
            int s = 0;
            while(n % primes[i] == 0) n /= primes[i], s ++;
            vec.push_back({primes[i], s}); 
        }
    }
    if(n > 1) vec.push_back({n, 1});
    vector<int> fac;
    int num = vec.size();
    auto dfs = [&](auto &&self, int u, int p)->void
    {
        if(u == num)
        {
            fac.emplace_back(p);
            return;
        }
        for(int i = 0; i <= vec[u][1]; i ++)
        {
            self(self, u + 1, p);
            p *= vec[u][0];
        }
    };
    dfs(dfs, 0, 1);

    int ans = 0;
    for(auto x : fac)
    {
        if(x * b0 == gcd(x, b0) * b1 && gcd(a0, x) == a1) 
            ans ++;
    }

    cout << ans << '\n';
}

int main()  
{  
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    sieve(50000);
    while(t --)
    {
        solve();
    }
}  