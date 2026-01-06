#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    int n, r;
    cin >> n >> r;
    vector<int> qry(n);
    for(int i = 0; i < n; i ++)
    {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        int res = 0;
        int r = 1;
        for(auto c : s)
        {
            res += (c - '0') * r;
            r *= 2; 
        }
        qry[i] = res;
    }


    int m;
    cin >> m;
    vector<int> sel(m);
    for(int i = 0; i < m; i ++)
    {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        int res = 0;
        int r = 1;
        for(auto c : s)
        {
            res += (c - '0') * r;
            r *= 2; 
        }
        sel[i] = res;
    }

    vector<array<int, 2>> num;
    num.reserve(pow(2, 10));

    auto dfs = [&](auto &&self, int u, int cnt, int res)->void
    {
        if(u == m)
        {
            num.push_back({res, cnt});
            return;
        }
        self(self, u + 1, cnt + 1, res | sel[u]);
        self(self, u + 1, cnt, res);
    };

    dfs(dfs, 0, 0, 0);

    for(int i = 0; i < n; i ++)
    {
        int ans = 1e9;
        for(auto [res, cnt] : num)
        {
            if((qry[i] | res) == res) ans = min(ans, cnt);
        }
        cout << (ans == 1e9 ? -1 : ans) << '\n';
    }
}