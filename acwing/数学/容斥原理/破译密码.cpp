#include<bits/stdc++.h> 
using namespace std;   
using i64 = long long;
vector<int> primes, minp;
vector<int> mu;

void sieve(int n)
{
    minp.assign(n + 1, 0);
    mu.resize(n + 1);

    mu[1] = 1;
    for(int i = 2; i <= n; i ++)
    {
        if(!minp[i])
        {
            primes.emplace_back(i);
            minp[i] = i;
            mu[i] = -1;
        }
        for(auto p : primes)
        {
            if(p * i > n) break;
            minp[i * p] = p;
            if(i % p == 0) break;
            mu[i * p] = -mu[i];
        }
    }
    for(int i = 1; i <= n; i ++) mu[i] += mu[i - 1];
}
  
int main()  
{  
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    sieve(500000);
    while(t --)
    {
        int a, b, d;
        cin >> a >> b >> d;
        a = a / d, b = b / d;
        int n = min(a, b);
        i64 ans = 0;
        for(int l = 1, r; l <= n; l = r + 1)
        {
            r = min(a / (a / l), b / (b / l));
            ans += 1ll * (a / l) * (b / l) * (mu[r] - mu[l - 1]);
        }
        cout << ans << '\n';
    }
}  