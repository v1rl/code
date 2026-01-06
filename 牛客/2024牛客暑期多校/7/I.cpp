#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int m, k, h;

bool check(int x)
{
    int t = m - k;
    i64 dmg = 0;
    if(x >= m)
    {
        int time = (x - m) / t + 1;
        int last = (x - m) % t;
        dmg = (i64)time * m + last + k;
    }
    else dmg = x;

    if(dmg >= h) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t ;
    cin >> t;
    while(t --)
    {
        cin >> m >> k >> h;
        int l = 0, r = h;
        if(m == k) cout << min(h, m) << '\n';
        else
        {
            while(l < r)
            {
                int mid = (l + r) >> 1;
                if(check(mid)) r = mid;
                else l = mid + 1;
            }
            cout << l << '\n';
        }
    }
}