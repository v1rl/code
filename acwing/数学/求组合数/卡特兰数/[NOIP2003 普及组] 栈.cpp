#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
i64 C[40][40];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i <= 2 * n; i ++)
    {
        for(int j = 0; j <= i; j ++)
        {
            if(j == 0) C[i][j] = 1;
            else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    cout << C[2 * n][n] / (n + 1);
}