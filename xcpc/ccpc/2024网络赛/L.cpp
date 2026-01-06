#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 510;
char g[N][N];
int dx[] = {0, 1, 1}, dy[] = {1, 0, 1};
char ck[] = {'c', 'p', 'c'};

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            cin >> g[i][j];

    int ans = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
        {
            if(g[i][j] != 'c') continue;
            int f = 0;
            for(int k = 0; k < 3; k ++)
            {
                int nx = i + dx[k], ny = j + dy[k];
                if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if(g[nx][ny] == ck[k]) f ++;
            }
            if(f == 3) ans ++;
        }
    cout << ans << '\n';
    return 0;
}   
