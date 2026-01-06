#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

struct DSU
{
    vector<int> p;
    DSU(int n = 0)
    {
        init(n);
    }

    void init(int n)
    {
        p.resize(n + 1, 0);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x)
    {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    bool merge(int x, int y)
    {
        x = find(x), y = find(y);
        if(x == y) return false;
        p[y] = x;
        return true;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    int ans = -1;
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
    char get[] = {'U', 'L', 'D', 'R'};

    auto getnum = [&](int x, int y)
    {
        return (x - 1) * n + y;
    };

    DSU dsu(n * n);

    for(int i = 1; i <= m; i ++)
    {
        int x, y;
        char op;
        cin >> x >> y >> op;
        if(ans == -1)
        {
            int index;
            for(int i = 0; i < 4; i ++)
            {
                if(op == get[i]) index = i;
            }
            int nx = x + dx[index], ny = y + dy[index];
            int getx = getnum(x, y), gety = getnum(nx, ny);
            if(dsu.same(getx, gety)) ans = i;
            else dsu.merge(getx, gety);
        }
    }   

    if(ans != -1) cout << ans << '\n';
    else cout << "draw" << '\n';
}