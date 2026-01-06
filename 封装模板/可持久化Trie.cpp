#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Trie
{
    vector<array<int, 2>> trie;
    vector<int> max_id;
    int idx = 0;

    Trie(int n) : trie(n * 24 + 1), max_id(n * 24 + 1) 
    {
        max_id[0] = -1;
    };

    void insert(int p, int &qq, int x, int id)
    {
        qq = ++ idx;
        int q = qq;
        for(int i = 23; i >= 0; i --)
        {
            int ch = (x >> i) & 1;
            if(p) trie[q][ch ^ 1] = trie[p][ch ^ 1];
            trie[q][ch] = ++ idx;

            p = trie[p][ch], q = trie[q][ch];
            max_id[q] = id;
        }
    }

    int find(int l, int p, int x)
    {
        int res = 0;
        for(int i = 23; i >= 0; i --)
        {
            int ch = (x >> i) & 1;
            // if(trie[p][ch ^ 1] && max_id[trie[p][ch ^ 1]] >= l)
            if(max_id[trie[p][ch ^ 1]] >= l)
            {
                p = trie[p][ch ^ 1];
                res += (1 << i);
            }
            else p = trie[p][ch];
        }
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    Trie trie(n + m + 1);
    vector<int> root(n + m + 1);
    vector<int> s(n + m + 1);
    trie.insert(0, root[0], 0, 0);

    for(int i = 1; i <= n; i ++)
    {
        cin >> s[i];
        s[i] ^= s[i - 1];
        trie.insert(root[i - 1], root[i], s[i], i);
    }

    while(m --)
    {
        char op;
        cin >> op;
        if(op == 'A')
        {
            n ++;
            cin >> s[n];
            s[n] ^= s[n - 1];
            trie.insert(root[n - 1], root[n], s[n], n);
        }
        else
        {
            int l, r, x;
            cin >> l >> r >> x;
            cout << trie.find(l - 1, root[r - 1], x ^ s[n]) << '\n';
        }
    }
}

