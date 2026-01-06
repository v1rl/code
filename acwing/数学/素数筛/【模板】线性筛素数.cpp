#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<int> primes, minp;
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
            minp[p * i] = p;
            if(p == minp[i]) break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    sieve(n);
    while(q --)
    {
        int x;
        cin >> x;
        cout << primes[x - 1] << '\n';
    }
}