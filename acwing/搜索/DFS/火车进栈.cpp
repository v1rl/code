#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> ans;
    vector<int> stk;
    int cnt = 0;
    auto dfs = [&](auto &&self, int u)->void
    {
        if(cnt == 20) return;
        if(ans.size() == n)
        {
            cnt ++;
            for(auto c : ans) cout << c;
            cout << '\n';
            return;
        }

        if(!stk.empty())
        {
            int x = stk.back();
            ans.emplace_back(x);
            stk.pop_back();
            self(self, u);
            ans.pop_back();
            stk.push_back(x);
        }
        if(u <= n)
        {
            stk.push_back(u);
            self(self, u + 1);
            stk.pop_back();
        }
    };

    dfs(dfs, 1);
    return 0;
}