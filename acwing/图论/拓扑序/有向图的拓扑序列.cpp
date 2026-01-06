#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> din(n + 1);
    for(int i = 1; i <= m; i ++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        din[y] ++;
    }

    queue<int> q;
    vector<int> ans;
    ans.reserve(n);
    for(int i = 1; i <= n; i ++) 
        if(!din[i])
            q.push(i);

    while(q.size())
    {
        int x = q.front();
        q.pop();
        ans.emplace_back(x);
        for(auto y : adj[x])
        {
            if(-- din[y] == 0) q.push(y);
        }
    }

    if(ans.size() == n)
    {
        for(auto x : ans) cout << x << ' ';
    }
    else cout << -1 << '\n';
}