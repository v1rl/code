#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int get1side(int n, int k)
{
    int res = 0;
    for(int i = 1; i <= k; i *= 2)
    {
        if(n & i)
            res += k / i;
    }
    return res;
}

int get(int x1, int x2, int y1, int y2, int k)
{
    if(x1 <= 0 && x2 >= k && y1 <= 0 && y2 >= k) return 1;
    if(x1 >= k || x2 <= 0 || y1 >= k || y2 <= 0) return 0;

    if(x1 <= 0 && x2 >= k && y1 <= 0)
    {
        return get1side(y2, k);
    }
    if(x1 <= 0 && x2 >= k && y2 >= k)
    {
        return get1side(k - y1, k);
    }
    if(y1 <= 0 && y2 >= k && x1 <= 0)
    {
        return get1side(x2, k);
    }
    if(y1 <= 0 && y2 >= k && x2 >= k)
    {
        return get1side(k - x1, k);
    }

    k /= 2;
    return get(x1, x2, y1, y2, k) + get(x1, x2, y1 - k, y2 - k, k) + get(x1 - k, x2 - k, y1, y2, k) + get(x1 - k, x2 - k, y1 - k, y2 - k, k);
}

void solve()
{
    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    cout << get(x1, x2, y1, y2, 1 << 20) << '\n';
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