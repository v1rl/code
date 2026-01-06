#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    vector<vector<int>> adj(n1 + 1);
    while(m --)
    {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
    }

    vector<int> match(n2 + 1);
    vector<int> st(n2 + 1);
    auto dfs = [&](auto &&self, int x)->bool
    {
        for(auto y : adj[x])
        {
            if(st[y]) continue;
            st[y] = true;
            if(!match[y] || self(self, match[y]))
            {
                match[y] = x;
                return true;
            }
        }
        return false;
    };

    int ans = 0;
    for(int i = 1; i <= n1; i ++)
    {
        st.assign(n2 + 1, 0);
        if(dfs(dfs, i)) ans ++; 
    }
    cout << ans << '\n';
    return 0;
}