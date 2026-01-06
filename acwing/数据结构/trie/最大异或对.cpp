#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Trie
{
    vector<array<int, 2>> trie;
    int idx = 0;

    Trie(int n_) : trie(n_ * 31) {};

    void insert(int x)
    {
        int p = 0;
        for(int i = 30; i >= 0; i --)
        {
            int ch = (x >> i) & 1;
            if(!trie[p][ch]) trie[p][ch] = ++idx;
            p = trie[p][ch];
        }
    }

    int find(int x)
    {
        int p = 0;
        int ans = 0;
        for(int i = 30; i >= 0; i --)
        {
            int ch = (x >> i) & 1;
            if(trie[p][ch ^ 1]) 
            {
                ans += 1 << i;
                p = trie[p][ch ^ 1];
            }
            else p = trie[p][ch];
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    Trie trie(n);
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        trie.insert(a[i]);
    }

    int mx = 0;
    for(int i = 1; i <= n; i ++)
    {
        mx = max(mx, trie.find(a[i]));
    }

    cout << mx << '\n';
    return 0;
}