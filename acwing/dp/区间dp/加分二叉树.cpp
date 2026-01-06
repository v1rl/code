#include<bits/stdc++.h>
using namespace std;
const int N = 35;
int a[N];
int f[N][N];
int g[N][N];

void dfs(int l, int r)
{
    if(l > r) return;
    int k = g[l][r];
    cout << g[l][r] << ' ';
    dfs(l, k - 1);
    dfs(k + 1, r);
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    for(int len = 1; len <= n; len ++)
        for(int l = 1; l + len - 1 <= n; l ++)
        {
            int r = l + len - 1;
            if(len == 1) f[l][r] = a[l], g[l][r] = l;
            else
            {
                for(int k = l; k <= r; k ++)
                {
                    int left = k == l ? 1 : f[l][k - 1];
                    int right = k == r ? 1 : f[k + 1][r];
                    int score = a[k] + left * right;
                    if(score > f[l][r])
                    {
                        f[l][r] = score;
                        g[l][r] = k;
                    }
                }
            }
        }

    cout << f[1][n] << '\n';
    dfs(1, n);
    return 0;
}
