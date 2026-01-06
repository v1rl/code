#include <bits/stdc++.h>
using namespace std;

vector<int> minp, primes;
void sieve(int n)
{
    minp.assign(n + 1, 0);
    for(int i = 2; i <= n; i ++)
    {
        if(minp[i] == 0)
        {
            minp[i] = i;
            primes.emplace_back(i);
        }
        for(auto p : primes)
        {
            if(p * i > n) break;
            minp[p * i] = p;
            if(p == minp[i]) break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    sieve(100);
    for(int i = 6; i <= 100; i ++)
    {
        if(i & 1) continue;
        for(auto p : primes)
        {
            int q = i - p;
            if(minp[q] == q)
            {
                printf("%d=%d+%d\n", i, p, q);
                break;
            }
        }
    }
    return 0;
}