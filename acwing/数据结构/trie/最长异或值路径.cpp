#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = N * 31;
int trie[M][2];
int cnt = 0;
int a[N];
typedef pair<int, int> PII;

void insert(int x)
{
    int p = 0;
    for(int i = 30; i >= 0; i --)
    {
        int ch = x >> i & 1;
        if(!trie[p][ch]) trie[p][ch] = ++cnt;
        p = trie[p][ch];
    }
}

int find(int x)
{
    int p = 0;
    int res = 0;
    for(int i = 30; i >= 0; i --)
    {
        int ch = x >> i & 1;
        if(trie[p][ch ^ 1])
        {
            p = trie[p][ch ^ 1];
            res += 1 << i;
        }
        else p = trie[p][ch];
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<vector<PII>> adj(n);
    for(int i = 0; i < n - 1; i ++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].emplace_back(y, w);
        adj[y].emplace_back(x, w);
    }

    auto dfs = [&](auto &&self, int x, int p)->void
    {
        for(auto [y, w] : adj[x])
        {
            if(y == p) continue;
            a[y] = a[x] ^ w;
            self(self, y, x);
        }
    };

    dfs(dfs, 0, -1);
    for(int i = 0; i < n; i ++) insert(a[i]);

    int res = 0;
    for(int i = 0; i < n; i ++)
        res = max(res, find(a[i]));
 
    cout << res << '\n';
}