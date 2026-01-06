#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

vector<int> minp, primes;
void sieve(int n)
{
    minp.assign(n + 1, 0);
    for(int i = 2; i <= n; i ++)
    {
        if(minp[i] == 0)
        {
            primes.emplace_back(i);
            minp[i] = i;
        }
        for(auto p : primes)
        {
            if(i * p > n) break;
            minp[i * p] = p;
            if(minp[i] == p) break;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    sieve(n);
    for(auto p : primes)
    {
        int cnt = 0;
        for(int i = p; i <= n; i *= p)
        {
            cnt += n / i;
        }
        cout << p << ' ' << cnt << '\n';
    }
    return 0;
}