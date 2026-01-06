#include<bits/stdc++.h> 
using namespace std;   
using i64 = long long;
  
int main()  
{  
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> row(n + 1);
    vector<vector<int>> col(n + 1);
    for(int i = 0; i < m; i ++)
    {
        int x, y;
        cin >> x >> y;
        row[x].emplace_back(y);
        col[y].emplace_back(x);
    }

    int ans = 0;
    for(auto &k : row)
    {
        if(k.size() <= 1) continue;
        sort(k.begin(), k.end());
        ans = max(ans, k.back() - k[0]);
    }
    for(auto &k : col)
    {
        if(k.size() <= 1) continue;
        sort(k.begin(), k.end());
        ans = max(ans, k.back() - k[0]);
    }

    cout << ans << '\n';
}  
