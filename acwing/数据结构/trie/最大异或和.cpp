#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 6e5 + 10;
int s[N];

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

    void insert(int u, int p, int q)
    {
        p = root[p], q = root[q] = ++ idx;
        for(int i = 23; i >= 0; i --)
        {
            int ch = (s[u] >> i) & 1;
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
    int n, m;
    cin >> n >> m;
    Trie trie(N);
    for(int i = 1; i <= n; i ++)
    {
        cin >> s[i];
        s[i] ^= s[i - 1];
        trie.insert(i, i - 1, i);
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
            trie.insert(n, n - 1, n);
        }
        else
        {
            int l, r, x;
            cin >> l >> r >> x;
            cout << trie.find(l - 1, r - 1, x ^ s[n]) << '\n';
        }
    }
}

