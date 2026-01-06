#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int s[N][N];
double f[N][N][N][N][N];
double X;
int n;

double get(int x1, int y1, int x2, int y2)
{
    int num = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] - X;
    return (double)num * num / n;
}

double dp(int x1, int y1, int x2, int y2, int k)
{
    double &v = f[x1][y1][x2][y2][k];
    if(v > 0) return v;
    if(k == 1) return get(x1, y1, x2, y2);
    v = 1e9;
    for(int i = x1; i < x2; i ++)
    {
        v = min(v, dp(x1, y1, i, y2, k - 1) + get(i + 1, y1, x2, y2));
        v = min(v, dp(i + 1, y1, x2, y2, k - 1) + get(x1, y1, i, y2));
    }
    for(int i = y1; i < y2; i ++)
    {
        v = min(v, dp(x1, y1, x2, i, k - 1) + get(x1, i + 1, x2, y2));
        v = min(v, dp(x1, i + 1, x2, y2, k - 1) + get(x1, y1, x2, i));
    }
    return v;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for(int i = 1; i <= 8; i ++)
        for(int j = 1; j <= 8; j ++)
        {
            cin >> s[i][j];
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }

    memset(f, -1, sizeof f);
    X = s[8][8] / n;

    printf("%.3lf", sqrt(dp(1, 1, 8, 8, n)));
}
