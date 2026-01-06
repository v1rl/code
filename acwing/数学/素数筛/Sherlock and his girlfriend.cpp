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
    int n;
    cin >> n;
    n ++;
    sieve(n);
    cout << (n <= 3 ? 1 : 2) << '\n';
    for(int i = 2; i <= n; i ++)
    {
        if(minp[i] == i) cout << 1 << ' ';
        else cout << 2 << ' ' ;
    }
    return 0;
}