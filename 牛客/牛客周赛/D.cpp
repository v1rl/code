#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

i64 get(int l, int r)
{
    return (1 + r - l) * (r - l) / 2;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        int x, len;
        cin >> x >> len;
        int l = (1 + x) / 2 - len / 2;
        int r = l + len;
        int mid = (1 + x) / 2;

        i64 ans = get(1, l) + get(r, x);
        int t = len - 1;
        if(t > 0)
        {
            if(t & 1)
            {
                t /= 2;
                ans += get(l, l + t + 1) + get(r - t, r);
            }
            else
            {
                t /= 2;
                ans += get(l, l + t) * 2;
            }
        }

        i64 res = get(1, mid) + get(mid, x);

        if(ans < res) cout << l << ' ' << r << ' ' << ans << '\n';
        else cout << mid << ' ' << mid + len << ' ' << res << '\n';
    }
}