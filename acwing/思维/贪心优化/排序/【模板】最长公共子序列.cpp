#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
typedef pair<int, int> PII;
const int inf = 2e9;

void solve()
{
    int n;
    cin >> n;
    vector<int> mp(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        mp[x] = i;
    }
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        a[i] = mp[x];
    }

    vector<int> s;
    for(int i = 1; i <= n; i ++)
    {
        int pos = lower_bound(s.begin(), s.end(), a[i]) - s.begin();
        if(pos == s.size()) s.emplace_back(a[i]);
        else s[pos] = a[i];
    }
    cout << s.size() << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t --)
    {
        solve();
    }
}