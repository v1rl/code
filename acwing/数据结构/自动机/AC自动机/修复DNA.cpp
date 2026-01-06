#include<bits/stdc++.h>
using namespace std; 
using i64 = long long;
const int inf = 1e9 + 10;

struct Ahocorasick
{
    int n;
    vector<array<int, 4>> trie;
    vector<int> ne;
    vector<int> ed;
    int idx = 0;

    Ahocorasick(int n_) : n(n_), trie(n + 1), ne(n + 1), ed(n + 1) {};

    int get(char c)
    {
        if(c == 'A') return 0;
        if(c == 'C') return 1;
        if(c == 'G') return 2;
        return 3;
    }

    void insert(string s)
    {
        int p = 0;
        for(auto c : s)
        {
            int ch = get(c);
            if(!trie[p][ch]) trie[p][ch] = ++ idx;
            p = trie[p][ch];
        }
        ed[p] = true;
    }

    void build()
    {
        queue<int> q;
        for(int i = 0; i < 4; i ++)
        {
            if(trie[0][i])
                q.push(trie[0][i]);
        }
        while(q.size())
        {
            int x = q.front();
            int lst = ne[x];
            q.pop();

            for(int i = 0; i < 4; i ++)
            {
                int &y = trie[x][i];
                if(!y) y = trie[lst][i];
                else
                {
                    ne[y] = trie[lst][i];
                    ed[y] |= ed[ne[y]];
                    q.push(y);
                }
            }
        }
    }

    void work(string s, int T)
    {
        int m = s.size();
        s = '#' + s;
        vector<vector<int>> f(m + 1, vector<int>(idx + 1, inf));
        f[0][0] = 0;
        for(int i = 0; i < m; i ++)
        {
            for(int j = 0; j <= idx; j ++)
            {
                for(int k = 0; k < 4; k ++)
                {
                    int t = get(s[i + 1]) != k;
                    int q = trie[j][k];
                    if(!ed[q]) f[i + 1][q] = min(f[i + 1][q], f[i][j] + t);
                }
            }
        }
        int ans = inf;
        for(int i = 0; i <= idx; i ++)
        {
            ans = min(ans, f[m][i]);
        }

        for(int i = 1; i <= m; i ++)
        {
            for(int j = 0; j <= idx; j ++)
            {
                cout << f[i][j] << " \n"[j == idx];
            }
        }

        // cout << (ans == inf ? -1 : ans) << '\n';
        printf("Case %d: %d\n", T, ans == inf ? -1 : ans);
    }

};

void solve()
{
    int n;
    int T = 0;
    while(cin >> n, n)
    {
        T ++;
        Ahocorasick ac(n * 50);
        for(int i = 1; i <= n; i ++)
        {
            string s;
            cin >> s;
            ac.insert(s);
        }
        ac.build();
        string s;
        cin >> s;
        ac.work(s, T);

    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t --)
    {
        solve();
    }
    return 0;
}