#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 65, M = 32010;
int v[N][10];
int w[N][10];
int s[N];
int f[M];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> m >> n;
    vector<vector<int>> bel(n + 1);
    vector<array<int, 3>> dat(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        int vi, wi, op;
        cin >> vi >> wi >> op;
        dat[i] = {vi, vi * wi, op};
        if(op) bel[op].push_back(i);
    }

    int cnt = 0;
    for(int i = 1; i <= n; i ++)
    {
        auto &[vi, wi, op] = dat[i];
        if(op != 0) continue;
        ++ cnt;
        int num = 0;
        int t = bel[i].size();
        for(int j = 0; j < (1 << t); j ++)
        {
            int nv = vi, nw = wi;
            for(int k = 0; k < t; k ++)
            {
                if(j >> k & 1)
                {
                	int pos = bel[i][k];
                    nv += dat[pos][0];
                    nw += dat[pos][1];
                }
            }
            ++ num;
            v[cnt][num] = nv, w[cnt][num] = nw;
        }
        s[cnt] = num;
    }

    for(int i = 1; i <= cnt; i ++)
        for(int j = m; j >= 1; j --)
            for(int k = 1; k <= s[i]; k ++)
                if(j >= v[i][k]) 
                	f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);

    cout << f[m] << '\n';
}