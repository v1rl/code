#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Node
{
    int win, lose;
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<Node> info(1 << n);
    for(int i = n; i >= 1; i --)
    {
        int m = 1 << (i - 1);
        int ls = m;
        for(int j = ls; j < ls + m; j ++)
        {
            cin >> info[j].lose;
        }
    }
    cin >> info[1].win;
    if(info[1].win < info[1].lose)
    {
        cout << "No Solution" << '\n';
        exit(0);
    }

    int siz = (1 << n) - 1;
    auto dfs = [&](auto &&self, int p)->bool
    {
        if((p << 1) > siz) return true;
        if(info[p].lose >= info[p << 1].lose && info[p].win >= info[p << 1 | 1].lose)
        {
            info[p << 1].win = info[p].lose;
            bool f1 = self(self, p << 1);
            info[p << 1 | 1].win = info[p].win;
            bool f2 = self(self, p << 1 | 1);
            if(f1 && f2) return true;
        }
        if(info[p].win >= info[p << 1].lose && info[p].lose >= info[p << 1 | 1].lose)
        {
            info[p << 1].win = info[p].win;
            bool f1 = self(self, p << 1);
            info[p << 1 | 1].win = info[p].lose;
            bool f2 = self(self, p << 1 | 1);
            if(f1 && f2) return true;
        }
        return false;
    };

    bool f = dfs(dfs, 1);
    if(!f)
    {
        cout << "No Solution" << '\n';
    }
    else
    {
        for(int i = 1 << (n - 1); i < (1 << n); i ++)
        {
            cout << info[i].win << ' ' << info[i].lose << ' ';
        }

    }
    return 0;
}