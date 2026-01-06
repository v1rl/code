#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
const int inf = 1e9;

struct Ahocorasick
{
    int n;
    vector<array<int, 26>> trie;
    vector<int> ne;
    vector<int> ed;
    int idx = 0;

    Ahocorasick(int n_) : n(n_), trie(n + 1), ne(n + 1), ed(n + 1) {};

    void insert(string s)
    {
        int p = 0;
        for(auto c : s)
        {
            int ch = c - 'a';
            if(!trie[p][ch]) trie[p][ch] = ++ idx;
            p = trie[p][ch];
        }
        ed[p] ++;
    }

    void build()
    {
        queue<int> q;
        for(int i = 0; i < 26; i ++)
        {
            if(trie[0][i]) q.push(trie[0][i]);
        }
        while(q.size())
        {
            int x = q.front();
            q.pop();

            int lst = ne[x];
            for(int i = 0; i < 26; i ++)
            {
                int &y = trie[x][i];
                if(!y) y = trie[lst][i];
                else
                {
                    ne[y] = trie[lst][i];
                    q.push(y);
                }
            }
        }
    }

    int query(string s)
    {
        i64 res = 0;
        int j = 0;
        for(auto c : s)
        {
            int ch = c - 'a';
            j = trie[j][ch];

            int p = j;
            while(p >= 1)
            {
                res += ed[p];
                ed[p] = 0;
                p = ne[p];
            }
        }
        return res;
    }
};

void solve()
{
    int n;
    cin >> n;
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
    cout << ac.query(s) << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    // t = 1;
    cin >> t;
    while(t --)
    {
        solve();
    }
}