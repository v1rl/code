#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

template<class T>
struct RMQ
{
    int n;
    vector<T> a;
    vector<vector<T>> stmax;
    RMQ(int n_, vector<T> &a_) : n(n_), a(a_), stmax(n + 1)
    {
        for(int i = 1; i <= n; i++)
        {
            stmax[i].resize(21, 0);
        }
        init();
    }

    void init()
    {
        for(int i = 1; i <= n; i ++) stmax[i][0] = a[i];
        for(int j = 1; (1 << j) <= n; j ++)
        {   
            for(int i = 1; i <= n - (1 << j) + 1; i ++)
            {
                stmax[i][j] = max(stmax[i][j - 1], stmax[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T askmax(int l, int r)
    {
        int len = log2(r - l + 1);
        return max(stmax[l][len], stmax[r - (1 << len) + 1][len]);
    }
};

struct Trie
{
    vector<array<int, 26>> trie;
    vector<int> root;
    vector<int> max_id;
    int idx = 0;

    Trie(int n) : trie(n + 1), root(n + 1), max_id(n + 1) 
    {
        max_id[0] = -1;
        insert("", 0, root[0]);
    };

    void insert(string s, int p, int q)
    {
        int u = q;
        p = root[p], q = root[q] = ++ idx;
        for(auto c : s)
        {
            int ch = c - 'a';
            for(int i = 0; i < 26; i ++)
            {
                if(i == ch) continue;
                if(p) trie[q][i] = trie[p][i];
            }
            trie[q][ch] = ++ idx;

            max_id[trie[q][ch]] = u;
            p = trie[p][ch], q = trie[q][ch];
        }
        for(int i = 0; i < 26; i ++)
        {
            if(p) trie[q][i] = trie[p][i];
        }
    }

    int find(int l, int p)
    {
        p = root[p];
        int cnt = 0;
        queue<int> q;
        q.push(p);
        while(q.size())
        {
            int p = q.front();
            q.pop();
            for(int i = 0; i < 26; i ++)
            {
                if(max_id[trie[p][i]] >= l)
                {
                    cnt ++;
                    q.push(trie[p][i]);
                }
            }
        }
        return cnt;
        // return x ^ s[max_id[p]];
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    Trie trie(3e6);
    int res = 0;
    int mxlen = 0;
    vector<string> s(n + 1);
    vector<int> len(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        cin >> s[i];
        len[i] = s[i].size();
        trie.insert(s[i], i - 1, i);
    }

    RMQ rmq(n, len);

    while(q --)
    {
        int l, r;
        cin >> l >> r;
        i64 res = 0;
        int mxlen = 0;
        int pans = trie.find(l, r);

        // int pans = trie.query(l, r, s[r])
        cout << pans * 2 - rmq.askmax(l, r) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    t = 1;
    // cin >> t;
    while(t --)
    {
        solve();
    }
}