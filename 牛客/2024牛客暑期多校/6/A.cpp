#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        cin >> n;
        vector<vector<array<int, 2>>> adj(n + 1);
        for(int i = 1; i < n; i ++)
        {
            int x, y, op;
            cin >> x >> y >> op;
            adj[x].push_back({y, op});
            adj[y].push_back({x, op});
        }


        string ans = "";
        double tans = 0;
        int l = -1, r = -1;
        int num0 = 0, num1 = 0;
        auto dfs = [&](auto && self, int x, int pa)->void
        {
            
            bool f = false;
            for(auto [y, op] : adj[x])
            {
                if(y == pa) continue;
                f = true;
                ans += char(op);
                if(op == 1) num1 ++;
                else if(op == 0) num0 ++;
                if(num0) tans = max(tans, (double)num1 / (num0 + num1));
                // if(op == 0 && l == -1) l = ans.size();
                // else if(op == 1 && l != -1 && r == -1) r = ans.size();
                self(self, y, x);
                // if(l == ans.size()) l = -1;
                // else if(r == ans.size()) r = -1;
                if(op == 1) num1 --;
                else if(op == 0) num0 --;
                ans.pop_back();
            }
            if(!f)
            {
                // if(l != -1 && r == -1) r = ans.size();
                // double res = 0;
                // if(num0 == 0) res = 1;
                // else if(num0 > num1) res = num1 / (num0 + num1);
                // else
                // {
                //     res = l / max(1, (r - 1));
                //     cout << res << '\n';
                // }
                // tans = max(tans, res);
                if(num0 == 0) tans = 1;
            }
        };
        dfs(dfs, 1, -1);
        printf("%.10lf\n", tans);
    }
}