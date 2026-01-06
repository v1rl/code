#include<bits/stdc++.h> 
using namespace std;   
using i64 = long long;

vector<int> minp, primes, phi;
void sieve(int n)
{
    minp.assign(n + 1, 0);
    phi.assign(n + 1, 0);
    
    phi[1] = 1;
    for(int i = 2; i <= n; i ++)
    {
        if(!minp[i])
        {
            minp[i] = i;
            phi[i] = i - 1;
            primes.emplace_back(i);
        }
        for(auto p : primes)
        {
            if(i * p > n) break;
            minp[i * p] = p;
            if(i % p == 0)
            {
                phi[i * p] = p * phi[i];
                break;
            }
            phi[i * p] = phi[i] * (p - 1);
        }
    }
}

int main()  
{  
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    sieve(1000);
    for(int j = 1; j <= t; j ++)
    {
        int n;
        cin >> n;
        int ans = 0;
        for(int i = 1; i <= n; i ++) 
            ans += phi[i];
        cout << j << ' ' << n << ' ' << ans * 2 + 1 << '\n';
    }
    return 0;
}  
