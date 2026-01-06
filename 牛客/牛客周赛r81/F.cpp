#include<bits/stdc++.h>
using namespace std; 
using i64 = long long;
const int inf = 1e9 + 10;

void solve()
{
    int n, k;
    cin >> n >> k;
    map<int, vector<array<i64, 2>>> mp;


    for(int i = 1; i <= k; i ++)
    {
        i64 x;
        cin >> x;
        auto check = [&](int mid)
        {
            i64 t = 1ll * (mid + 1) * mid / 2;
            return t >= x;
        };
        int l = 1, r = n;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        mp[l].push_back({x, x});
    }

    vector<vector<array<i64, 2>>> a;
    vector<int> step;
    for(auto &[x, y] : mp)
    {
        step.emplace_back(x);
        a.emplace_back(y);
    }

    reverse(a.begin(), a.end());
    reverse(step.begin(), step.end());

    i64 ans = 0;
    for(int i = 0; i < a.size(); i ++)
    {
        auto b = a[i];
        int down = step[i];
        sort(b.begin(), b.end());

        vector<array<i64, 2>> merged;
        i64 wl = -1, wr = -1;
        for(auto &[l, r] : b)
        {
            if(wl != -1 && l <= wr + 1)
            {
                wr = max(wr, r);
            }
            else
            {
                if(wl != -1) merged.push_back({wl, wr});
                wl = l, wr = r;
            }
        }
        merged.push_back({wl, wr});

        int up = 0;
        if(i + 1 < a.size())
        {
            up = step[i + 1];
        }

        for(auto &[l, r] : merged)
        {
            int len = r - l + 1;
            if(up <= down - len)
            {
                ans += 1ll * (len + 1) * len / 2;
            }
            else
            {
                int h = down - up;
                i64 nl = l - (1ll * down * h - 1ll * (h + 1) * h / 2);
                i64 nr = r - (1ll * down * h - 1ll * h * (h - 1) / 2);
                ans += 1ll * (len + len - h + 1) * h / 2;
                if(i + 1 < a.size())
                {
                    a[i + 1].push_back({nl, nr});
                }
            }
        }
        // cout << ans << '\n';
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    // t = 1;
    while(t --)
    {
        solve();
    }
    return 0;
}