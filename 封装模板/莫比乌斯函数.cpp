#include<bits/stdc++.h> 
using namespace std;   
using i64 = long long;

vector<int> minp, primes, mu;
void sieve(int n)
{
    minp.assign(n + 1, 0);
    mu.assign(n + 1, 0);

    mu[1] = 1;
    for(int i = 2; i <= n; i ++)
    {
        if(!minp[i])
        {
            mu[i] = -1;
            minp[i] = i;
            primes.emplace_back(i);
        }
        for(auto p : primes)
        {
            if(p * i > n) break;
            minp[p * i] = p;
            if(i % p == 0) break;
            mu[i * p] = -mu[i];
        }
    }

    for(int i = 1; i <= n; i ++) mu[i] += mu[i - 1];
}
  
int main()  
{  
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    sieve(n);
}  
