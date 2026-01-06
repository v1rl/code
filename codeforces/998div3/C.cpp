#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    int ans = 0;
    for(int l = 1, r = n; l < r; )
    {
        if(a[l] + a[r] == k)
        {
            ans ++;
            l ++, r --;
        }
        else if(a[l] + a[r] < k) l ++;
        else if(a[l] + a[r] > k) r --;
    }
    cout << ans << '\n';
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