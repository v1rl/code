#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        int n, m;
        cin >> n >> m;
        vector<int> st(n + 1);
        vector<int> ls(n + 1);
        queue<PII> q;
        for(int i = 1; i <= m; i ++)
        {
            int x;
            cin >> x;
            q.push({0, x});
            st[x] = true;
        }
        vector<vector<int>> adj(n + 1);
        for(int i = 1; i < n; i ++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        int ans = 0;
        while(q.size())
        {
            auto [p, x] = q.front();
            q.pop();
            int num = 0;
            for(auto y : adj[x])
            {
                if(!st[y])
                {
                    st[y] = true;   
                    num ++;
                    q.push({x, y});
                }
                if(num == 2)
                {
                    num = 0;
                    ans ++;
                }
            }
            if(num > 0) ans ++;
            if(num == 1)
            {
                ls[x] = 1;
                if(ls[p])
                {
                    ans --;
                    ls[x] = 0, ls[p] = 0;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}   