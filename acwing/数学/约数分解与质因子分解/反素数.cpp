#include<bits/stdc++.h> 
using namespace std;   
using i64 = long long;
int primes[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

int main()  
{  
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    int num = 0;
    i64 ans = 0;
    auto dfs = [&](auto &&self, int u, int m, i64 p, int q)->void
    {
        if(u > 8) return;
        if(q > num)
        {
            num = q;
            ans = p;
        }   
        else if(q == num) ans = min(ans, p);
        for(int i = 1; i <= m; i ++)
        {
            p *= primes[u];
            if(p > n) break;
            self(self, u + 1, i, p, q * (i + 1));
        }
    };
    dfs(dfs, 0, 30, 1, 1);
    cout << ans << '\n';
}  