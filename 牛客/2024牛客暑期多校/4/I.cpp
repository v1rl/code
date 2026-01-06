#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    unordered_set<int> S[n];
    for(int i = 0; i < m; i ++)
    {
        int x, y;
        cin >> x >> y;
        x --, y --;
        S[x].insert(y);
        S[y].insert(x);
    }

    i64 ans = 0;
    for(int r = 0, l = 0; r < n; r ++)
    {
        bool f = false;
        while(!f)
        {
            f = true;
            for(int i = l; i < r; i ++)
            {
                if(!S[r].count(i))
                {
                    f = false;
                    break;
                }
            }
            if(!f) l ++;
        }
        ans += r - l + 1;
    }
    cout << ans << '\n';
}
