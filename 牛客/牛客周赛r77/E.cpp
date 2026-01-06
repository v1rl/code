#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e18;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<array<i64, 2>> sum;
    sum.reserve(n);
    int l = 1, r = 1;
    a[0] = 2;
    while(r <= n)
    {
        char c;
        cin >> c;
        a[r] = c - '0';
        if(r == 1 || a[r] != a[r - 1])
        {
            i64 m = r - l;
            i64 s = (m + 1) * m / 2;
            sum.push_back({r, a[l] == 0 ? s : 0});
            l = r;
        }
        r ++;
    }
    i64 m = r - l;
    sum.push_back({r, a[l] == 0 ? m * (m + 1) / 2 : 0});
    for(int i = 1; i < sum.size(); i ++)
    {
        sum[i][1] += sum[i - 1][1];
    }

    int q;
    cin >> q;
    while(q --)
    {
        int l, r;
        cin >> l >> r;
        int nl = lower_bound(sum.begin(), sum.end(), array<i64, 2>{l, 0}) - sum.begin();
        int nr = upper_bound(sum.begin(), sum.end(), array<i64, 2>{r, inf}) - sum.begin();
        nr --;
        i64 res = 0;
        if(nr < nl)
        {   
            if(!a[l])
            {
                i64 m = r - l + 1;
                res += m * (m + 1) / 2;
            }
        }
        else
        {
            res += sum[nr][1] - sum[nl][1];
            if(!a[l])
            {
                i64 m = sum[nl][0] - l;
                res += m * (m + 1) / 2;
            }
            if(!a[r])
            {
                i64 m = r - sum[nr][0] + 1;
                res += m * (m + 1) / 2;
            }
        }
        i64 m = r - l + 1;
        i64 ans = m * (m + 1) / 2;
        cout << ans - res << '\n';
    }
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