#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int mod = 1e9 + 7, N = 3;

void mul(int c[], int a[], int b[][N])
{
    int tep[N] = {0};
    for(int j = 0; j < N; j ++)
        for(int k = 0; k < N; k ++)
        {
            tep[j] = (tep[j] + 1ll * a[k] * b[k][j]) % mod;
        }
    memcpy(c, tep, sizeof tep);
}

void mul(int c[][N], int a[][N], int b[][N])
{
    int tep[N][N] = {0};
    for(int i = 0; i < N; i ++)
        for(int j = 0; j < N; j ++)
            for(int k = 0; k < N; k ++)
                tep[i][j] = (tep[i][j] + 1ll * a[i][k] * b[k][j]) % mod;
    memcpy(c, tep, sizeof tep);
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    i64 n;
    cin >> n;
    int a[N][N] = {
        {0, 1},
        {1, 1}
    };
    n --;
    int res[N] = {1, 1};
    while(n)
    {
        if(n & 1) mul(res, res, a);
        mul(a, a, a);
        n >>= 1;
    }
    cout << res[0] << '\n';
}