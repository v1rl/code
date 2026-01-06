#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<string> s(n);
    for(int i = 0; i < n; i ++)
    {
        cin >> s[i];
    }
    sort(s.begin(), s.end());

    auto lcp = [&](string a, string b)->int
    {
        int len = min(a.size(), b.size());
        for(int i = 0; i < len; i ++)
        {
            if(a[i] != b[i]) return i;
        }
        return len;
    };

    while(q --)
    {
        int l, r;
        cin >> l >> r;
        sort(s.begin() + l - 1, s.begin() + r);
        int x = s[l - 1].size();
        int mx = s[l - 1].size();
        for(int i = l; i < r; i ++)
        {
            int len = s[i].size();
            x += len;
            mx = max(len, mx);
            x -= lcp(s[i], s[i - 1]);
        }
        cout << 2 * x - mx << '\n';
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