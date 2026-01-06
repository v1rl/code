#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int N = 510;
int n, x, y;
int g[N][N];
int idx = 0;

void dfs(int sx, int sy, int x, int y, int siz)
{
    if(siz == 1) return;
    siz /= 2;
    int c = ++ idx;
    int nx = sx + siz, ny = sy + siz;

    if(x <= nx && y <= ny)
    {
        dfs(sx, sy, x, y, siz);
    }
    else
    {
        g[nx][ny] = c;
        dfs(sx, sy, nx, ny, siz);
    }

    if(x <= nx && y > ny)
    {
        dfs(sx, sy + siz, x, y, siz);
    }
    else
    {
        g[nx][ny + 1] = c;
        dfs(sx, sy + siz, nx, ny + 1, siz);
    }

    if(x > nx && y <= ny)
    {
        dfs(sx + siz, sy, x, y, siz);
    }
    else
    {
        g[nx + 1][ny] = c;
        dfs(sx + siz, sy, nx + 1, ny, siz);
    }

    if(x > nx && y > ny)
    {
        dfs(sx + siz, sy + siz, x, y, siz);
    }
    else
    {
        g[nx + 1][ny + 1] = c;
        dfs(sx + siz, sy + siz, nx + 1, ny + 1, siz);
    }
}

int main()
{   
    scanf("%d%d%d", &n, &x, &y);
    g[x][y] = 0;
    n = (1 << n);
    dfs(0, 0, x, y, n);

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
    return 0;
}