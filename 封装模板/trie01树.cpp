#include <bits/stdc++.h>
using namespace std;


struct Trie
{
    vector<array<int, 2>> trie;
    vector<int> root;
    vector<int> max_id;
    int idx = 0;

    Trie(int n) : trie(n * 24), root(n), max_id(n * 24) 
    {
        max_id[0] = -1;
        insert(0, 0, root[0]);
    };

    void insert(int x, int p, int q)
    {
        int u = q;
        p = root[p], q = root[q] = ++ idx;
        for(int i = 23; i >= 0; i --)
        {
            int ch = (x >> i) & 1;
            if(p) trie[q][ch ^ 1] = trie[p][ch ^ 1];
            trie[q][ch] = ++ idx;

            max_id[trie[q][ch]] = u;
            p = trie[p][ch], q = trie[q][ch];
        }
    }

    int find(int l, int p, int x)
    {
        p = root[p];
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
        // return x ^ s[max_id[p]];
    }
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    Trie trie(n);
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        trie.insert(a[i]);
    }
    int res = 0;
    for(int i = 1; i <= n; i ++)
        res = max(res, trie.query(a[i]));
    cout << res << '\n';
    return 0;
}