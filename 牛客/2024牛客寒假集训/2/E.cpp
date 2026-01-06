#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
typedef pair<int, int> PII;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<i64> sum(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    vector<vector<PII>> query(n + 1);
    vector<int> ans(q + 1);
    for(int i = 1; i <= q; i ++)
    {
        int l, r;
        cin >> l >> r;
        query[r].emplace_back(l, i);
    }

    vector<i64> res(n + 1);
    for(int i = 1; i <= n; i ++) res[i] = a[i] - sum[i - 1];

    vector<int> stk;
    for(int i = 1; i <= n; i ++)
    {
        while(!stk.empty() && res[stk.back()] < res[i])
        {
            stk.pop_back();
        }
        stk.push_back(i);
        for(auto [l, id] : query[i])
        {
            auto pos = upper_bound(stk.begin(), stk.end(), l);
            if(pos == stk.end())
            {
                ans[id] = 0;
                continue;
            }
            ans[id] = max(0ll, res[*pos] + sum[l - 1]);
        }
    }

    for(int i = 1; i <= q; i ++) cout << ans[i] << '\n';
    return 0;
}