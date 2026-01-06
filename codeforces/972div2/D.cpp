#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 5e5 + 10;
int a[N], b[N];
int pa[N], pb[N], sa[N], sb[N];
int n;

i64 solve1(int ca, int cb)
{
    if(cb <= 0) return 0;
    if(b[1] % cb) return 0;

    array<i64, 3> dp;
    dp.fill(0);
    dp[0] = 1;
    for(int i = 2; i <= n; i ++)    // 第一个元素作为基底不执行交换
    {
        for(int j = 2; j >= 0; j --)
        {
            bool flag = true;
            if(j == 1)
            {
                if(a[i] % cb) flag = false;
                if(b[i] % ca) flag = false;
                if(flag) dp[1] = dp[0] + dp[1];
                else dp[1] = 0;
            }
            else
            {
                if(a[i] % ca) flag = false;
                if(b[i] % cb) flag = false;
                if(flag)
                {
                    if(j == 0) dp[0] = dp[0];
                    else if(j == 2) dp[2] = dp[2] + dp[1];
                }
                else dp[j] = 0;
            }
        }
    }
    return dp[1] + dp[2];
}

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) cin >> b[i];
    sa[n + 1] = sb[n + 1] = 0;
    for(int i = 1, j = n; i <= n; i ++, j --)
    {
        pa[i] = gcd(pa[i - 1], a[i]);
        pb[i] = gcd(pb[i - 1], b[i]);
        sa[j] = gcd(sa[j + 1], a[j]);
        sb[j] = gcd(sb[j + 1], b[j]);
    }

    if(n <= 30)
    {
        int max_gcd = 0, cnt = 0;
        for(int l = 1; l <= n; l ++)
        {
            int ga = 0, gb = 0;
            for(int r = l; r <= n; r ++)
            {
                ga = gcd(ga, a[r]), gb = gcd(gb, b[r]);
                int ca = gcd(pa[l - 1], gcd(gb, sa[r + 1]));
                int cb = gcd(pb[l - 1], gcd(ga, sb[r + 1]));
                if(ca + cb > max_gcd) max_gcd = ca + cb, cnt = 1;
                else if(ca + cb == max_gcd) cnt ++;
            }
        }

        cout << max_gcd << ' ' << cnt << '\n';
        return;
    }

    int max_gcd = pa[n] + pb[n];
    // int max_gcd = 0;
    for(int l = 2; l <= n; l ++)
    {
        if(pa[l] == pa[l - 1] && pb[l] == pb[l - 1]) continue;

        int ga = 0, gb = 0;
        for(int r = l; r <= n; r ++)
        {
            ga = gcd(ga, a[r]);
            gb = gcd(gb, b[r]);
            int ca = gcd(pa[l - 1], gcd(gb, sa[r + 1]));
            int cb = gcd(pb[l - 1], gcd(ga, sb[r + 1]));
            max_gcd = max(max_gcd, ca + cb);
        }
    }

    i64 cnt = 0;
    for(int ca = 1; ca <= a[1] / ca; ca ++)
    {
        if(a[1] % ca) continue;
        cnt += solve1(ca, max_gcd - ca);
        if(ca == a[1] / ca) continue;
        cnt += solve1(a[1] / ca, max_gcd - a[1] / ca);
    }
    for(int i = 1; i <= n; i ++)
        if(gcd(pa[i], sb[i + 1]) + gcd(pb[i], sa[i + 1]) == max_gcd) cnt ++;

    cout << max_gcd << ' ' << cnt << '\n';
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