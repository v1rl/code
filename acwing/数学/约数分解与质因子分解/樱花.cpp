#include<bits/stdc++.h> 
using namespace std;   
using i64 = long long;
constexpr int mod = 1e9 + 7;

vector<int> minp, primes;
void sieve(int n)
{
    minp.assign(n + 1, 0);
    for(int i = 2; i <= n; i ++)
    {
        if(!minp[i])
        {
            primes.emplace_back(i);
            minp[i] = i;
        }
        for(auto p : primes)
        {
            if(p * i > n) break;
            minp[i * p] = p;
            if(i % p == 0) break; 
        }
    }
}

int main()  
{  
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    sieve(n);
    i64 ans = 1;
    for(auto p : primes)
    {
        int num = 0;
        for(i64 i = p; i <= n; i *= p)
        {
            num += n / i;
        }
        ans = ans * (num * 2 + 1) % mod;
    }
    cout << ans << '\n';
}  