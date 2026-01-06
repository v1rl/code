#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<array<int, 2>> dat(n);
    vector<int> alls;
    alls.reserve(n + q * 2);
    for(int i = 0; i < n; i ++)
    {
        int x, w;
        cin >> x >> w;
        dat[i] = {x, w};
        alls.emplace_back(x);
    }
    vector<array<int, 2>> query(q);
    for(int i = 0; i < q; i ++)
    {
        int l, r;
        cin >> l >> r;
        query[i] = {l, r};
        alls.emplace_back(l);
        alls.emplace_back(r);
    }
    sort(alls.begin(), alls.end());
    unordered_map<int, int> mp;
    // vector<int> val(n + q * 2 + 1);
    int cnt = 0;
    for(auto x : alls)
    {
        if(mp.count(x)) continue;
        mp[x] = ++ cnt;
        // val[cnt] = x;
    }
    vector<int> s(cnt + 1);
    for(auto [x, w] : dat) 
    {
        s[mp[x]] += w;
    }
    for(int i = 1; i <= cnt; i ++) s[i] += s[i - 1];
    for(auto [l, r] : query)
    {
        cout << s[mp[r]] - s[mp[l] - 1] << '\n';
    }
    return 0;
}