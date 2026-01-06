#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> b(m);
    for(int i = 0; i < m; i ++) cin >> b[i];
    sort(b.begin(), b.end());
    for(int i = 0; i < k; i ++)
    {
        int a;
        cin >> a;
        int ans;
        auto it = lower_bound(b.begin(), b.end(), a);
        if(it == b.begin()) ans = b[0] - 1;
        else if(it == b.end()) ans = n - b[m - 1];
        else ans = (*it - *(it - 1)) / 2;
        cout << ans << '\n';
    }
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