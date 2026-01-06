#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

void solve()
{
    int n, mod, k;
    cin >> n >> mod >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        a[i] %= mod;
    }
    sort(a.begin() + 1, a.end());

    auto work1 = [&](int x)
    {
        i64 ans = 0;
        for(int i = 1, j = n; i <= n; i ++)
        {
            while(j >= 1 && a[i] + a[j] > x) j --;
            ans += n - max(i, j);
        }
        return ans;
    };
    
    auto work2 = [&](int x)
    {
        i64 ans = 0;
        for(int i = 1, j = n; i <= n; i ++)
        {
            while(j >= 1 && a[i] + a[j] >= x) j --;
            ans += n - max(i, j);
        }
        return ans;
    };

    auto check = [&](int x)
    {
        return work1(x) - work2(mod) + work1(x + mod);
    };

    int l = -1, r = mod - 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid) <= k - 1) r = mid;
        else l = mid + 1;
    };

    vector<int> ans;
    for(int i = 1, j = n, v = n; i <= n; i ++)
    {
        while(j >= 0 && a[i] + a[j] > l) j --;
        while(v >= 0 && a[i] + a[v] > mod + l) v --;
        for(int c = max(i, j) + 1; c <= n; c ++)
        {
            if(a[i] + a[c] >= mod) break;
            ans.emplace_back(a[i] + a[c]);
        } 
        for(int c = max(i, v) + 1; c <= n; c ++)
        {
            ans.emplace_back((a[i] + a[c]) % mod);
        }
    }

    sort(ans.begin(),ans.end(),greater<int>());
    while(ans.size() < k) ans.push_back(r);
    for(auto x : ans) cout << x << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        solve();
    }
}