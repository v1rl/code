#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Trie
{
    vector<array<int, 26>> trie;
    vector<int> ed;
    int idx = 0;

    Trie(int n_) : trie(n_ + 1), ed(n_ + 1) {};

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

    int find(string s)
    {
        int p = 0;
        for(auto c : s)
        {
            int ch = c - 'a';
            if(!trie[p][ch]) return 0;
            p = trie[p][ch];
        }
        return ed[p];
    }
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    Trie trie(1e6);
    while(n --)
    {
        string s;
        cin >> s;
        trie.insert(s);
    }
    while(m --)
    {
        string s;
        cin >> s;
        int ans = 0;
        for(int i = 0; i < s.size(); i ++)
        {
            string t = s.substr(0, i + 1);
            ans += trie.find(t);
        }
        cout << ans << '\n';
    }
}