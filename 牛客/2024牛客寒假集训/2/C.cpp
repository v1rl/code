#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
typedef pair<int, int> PII;

void solve()
{
    int n;
    cin >> n;
    vector<string> s(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        cin >> s[i];
        s[i] = '#' + s[i];
    } 

    vector<array<int, 4>> ans;
    auto work = [&](int i, int j, int x, int y)
    {
        swap(s[i][j], s[x][y]);
        ans.push_back({i, j, x, y});
    };

    auto move = [&](int i, int j, int x, int y)
    {
        auto movex = [&]()
        {
            while(i < x)
            {
                work(i, j, i + 1, j);
                i ++;
            }
            while(i > x)
            {
                work(i, j, i - 1, j);
                i --;
            }
        };
        auto movey = [&]()
        {
            while(j < y)
            {
                work(i, j, i, j + 1);
                j ++;
            }
            while(j > y)
            {
                work(i, j, i, j - 1);
                j --;
            }
        };
        if(i < x)
        {
            movex();
            movey();
        }
        else
        {
            movey();
            movex();
        }
    };


    int x = 1, y = 1;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            while(s[i][j] == '1')
            {
                move(i, j, x, y);
                s[x][y] = '2';
                y ++;
                if(y == n / 2 + 1)
                {
                    x ++;
                    y = 1;
                }
            }
        }
    }

    cout << ans.size() << '\n';
    for(auto &[i, j, x, y] : ans)
    {
        cout << i << ' ' << j << ' ' << x << ' ' << y << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;

    while(t --)
    {
        solve();
    }
}