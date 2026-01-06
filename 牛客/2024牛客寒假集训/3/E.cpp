#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
typedef pair<int, int> PII;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<PII> ball;
    ball.reserve(n);
    int p = 0, q = 0;
    for(int i = 1; i <= n; i ++)
    {
        int x, t;
        cin >> x >> t;
        ball.emplace_back(x, t);
        if(t == -1) p ++;
        if(t == 1) q ++;
    }
    sort(ball.begin(), ball.end());

    auto check = [&](int x)->bool
    {
        vector<int> res;
        int j = 0;
        int ans = 0;
        for(auto [pos, op] : ball)
        {
            if(op == 1)
            {
                res.emplace_back(pos);
            }
            else
            {
                // int t = pos - x;
                // int index = lower_bound(res.begin(), res.end(), t) - res.begin();
                // ans += res.size() - index;
                while(j < res.size() && pos - res[j] > x) j ++;
                ans += res.size() - j;
            }
        }
        return (ans >= k);
    };

    int l = 0, r = 1e9 + 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    if(l == 1e9 + 1)
    {
        cout << "No" << '\n';
    }
    else
    {
        cout << "Yes" << '\n';
        printf("%.6lf\n", (double)l / 2);
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    t = 1;
    // cin >> t;
    while(t --)
    {
        solve();
    }
}