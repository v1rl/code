#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> st(m);
    vector<int> ans;
    ans.reserve(m);
    for(int i = 0; i < m; i ++) cin >> a[i];


    auto dfs = [&](auto &&self, int res, int u)->bool
    {
        if(u == m)
        {
            for(auto i : ans) cout << i + 1 << ' ';
            return true;
        }
        for(int i = 0; i < m; i ++)
        {
            if(st[i]) continue;
            if(res + a[i] > n) continue;
            st[i] = true;
            ans.emplace_back(i);
            if(self(self, max(res + a[i], 0), u + 1)) return true;
            ans.pop_back();
            st[i] = false;
        }
        return false;
    };
    
    if(!dfs(dfs, 0, 0)) cout << "-1" << '\n';
    return 0;
}
