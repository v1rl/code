#include<bits/stdc++.h>
using namespace std; 
using i64 = long long;
const int mod = 998244353;

void solve()
{
    string s;
    cin >> s;
    string t = s;
    int n = s.size();
    bool f = true;
    int l = 1e9, r = 0;
    unordered_map<char, set<int>> mp;

    for(int i = 0; i < n; i ++)
    {
        mp[s[i]].insert(i);
    }

    unordered_map<char, set<int>> mpt = mp;

    for(int i = 0, j = n - 1; i < j; i ++, j --)
    {
        if(s[i] == s[j])
        {
            mp[s[i]].erase(i);
            mp[s[j]].erase(j);
            continue;
        }
        mp[s[j]].erase(j);

        int pos = *mp[s[j]].begin();
        mp[s[j]].erase(pos);
        mp[s[i]].insert(pos);
        mp[s[i]].erase(i);

        swap(s[i], s[pos]);

        if(pos == i) continue;

        l = min(l, i), r = max(r, pos);
    }

    int ans = 0;
    if(l != 1e9) ans = r - l + 1;

    s = t;
    mp = mpt;
    l = 1e9, r = 0;

    for(int i = 0, j = n - 1; i < j; i ++, j --)
    {
        if(s[i] == s[j])
        {
            mp[s[i]].erase(i);
            mp[s[j]].erase(j);
            continue;
        }
        mp[s[i]].erase(i);

        int pos = *mp[s[i]].rbegin();
        mp[s[i]].erase(pos);
        mp[s[j]].insert(pos);
        mp[s[j]].erase(j);

        swap(s[j], s[pos]);

        if(pos == j) continue;
        r = max(r, j), l = min(l, pos);
    }

    if(l == 1e9) cout << ans << '\n';
    else cout << min(ans, r - l + 1) << '\n';
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