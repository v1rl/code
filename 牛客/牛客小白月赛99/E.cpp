#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    
    int t;
    cin >> t;
    while(t --)
    {
        int n, m;
        cin >> n >> m;
        vector<array<int, 2>> dat(n);
        for(int i = 0; i < n; i ++) cin >> dat[i][1];
        for(int i = 0; i < n; i ++) cin >> dat[i][0];
        sort(dat.begin(), dat.end());
        vector<bool> st(n);
        vector<int> ans;
        ans.reserve(n);
        for(int i = 0; i < n; i ++)
        {
            if(st[i]) continue;
            st[i] = true;
            auto [pos, h] = dat[i];
            int l = pos, r = pos + h;
            int num = 1;
            for(int j = i + 1; j < n; j ++)
            {
                auto [pos1, h1] = dat[j];
                if(pos1 >= l && pos1 <= r)
                {
                    st[j] = true;
                    num ++;
                    r = max(r, pos1 + h1);
                }
                else break;
            }
            ans.emplace_back(num);
        }
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        int res = 0;
        for(int i = 0; i < m; i ++)
        {
            res += ans[i];
            if(res == n) break;
        }
        cout << res << '\n';
    }
}