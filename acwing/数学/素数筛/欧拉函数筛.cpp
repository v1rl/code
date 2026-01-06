#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<int> minp, primes, phi;
void sieve(int n)
{
    minp.assign(n + 1, 0);
    phi.resize(n + 1);

    phi[1] = 1;
    for(int i = 2; i <= n; i ++)
    {
        if(!minp[i])
        {
            minp[i] = i;
            primes.emplace_back(i);
            phi[i] = i - 1;
        }
        for(auto p : primes)
        {
            if(i * p > n) break;
            minp[i * p] = p;
            if(minp[i] == p) 
            {
                phi[i * p] = phi[i] * p;
                break;
            }
            phi[i * p] = phi[i] * (p - 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    sieve(n);
    int ans = 0;
    for(int i = 1; i <= n; i ++) ans += phi[i];
    cout << ans << '\n';
}