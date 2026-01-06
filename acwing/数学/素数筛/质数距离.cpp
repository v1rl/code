#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

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

int ceil(i64 n, i64 m)
{
    if(n >= 0) return (n + m - 1) / m;
    return n / m;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int l, r;
    cin >> l >> r;
    sieve(sqrt(r + 1));
    vector<int> st(r - l + 1);
    for(auto p : primes)
    {
        for(i64 i = 1ll * max(2, ceil(l, p)) * p; i <= r; i += p)
        {
            st[i - l] = 1;
        }
    }
    int max_ans = 0;
    int min_ans = 1e9;
    int lst = -1;
    int mxl, mxr, mnl, mnr;
    for(int i = max(2, l); i <= r; i ++)
    {
        if(!st[i - l])
        {
            if(lst != -1)
            {
                if(max_ans < i - lst)
                {
                    max_ans = i - lst;
                    mxl = lst;
                    mxr = i;
                }
                if(min_ans > i - lst)
                {
                    min_ans = i - lst;
                    mnl = lst;
                    mnr = i;
                }
            }
            lst = i;
        }
    }
    if(max_ans) printf("%d,%d are closest, %d,%d are most distant.\n", mnl, mnr, mxl, mxr);
    else printf("There are no adjacent primes.\n");
    return 0;
}