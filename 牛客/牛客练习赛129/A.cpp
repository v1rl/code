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

int main()  
{  
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    sieve(n);
    vector<int> st(n + 1);
    for(auto p : primes)
        for(i64 i = p; i <= n; i *= p)
            st[i] = true;

    int ans = 0;
    for(int i = 2; i <= n; i ++)
        if(!st[i])
            ans ++;
    cout << ans << '\n';
}  
