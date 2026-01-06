#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int x1, x2;
int y11, y2;

int get1side(int n, int k)
{
    int ans = 0;
    for(int i = 1; i <= k; i *= 2)
    {
        if(n & i)
        {
            ans += k / i;
        }
    }
    return ans;
}

int get(int l1, int r1, int siz)
{
    int l2 = l1 + siz, r2 = r1 + siz;
    if(x2 <= l1 || x1 >= l2 || y2 <= r1 || y11 >= r2) return 0;
    if(x1 <= l1 && l2 <= x2 && y11 <= r1  && r2 <= y2) return 1;

    if(x1 <= l1 && l2 <= x2 && y11 <= r1)
    {
        return get1side(y2 - r1, siz);
    }
    if(x1 <= l1 && l2 <= x2 && r2 <= y2)
    {
        return get1side(r2 - y11, siz);
    }
    if(y11 <= r1 && r2 <= y2 && x1 <= l1)
    {
        return get1side(x2 - l1, siz);
    }
    if(y11 <= r1 && r2 <= y2 && l2 <= x2)
    {
        return get1side(l2 - x1, siz);
    }    

    siz /= 2;
    return get(l1, r1, siz) + get(l1 + siz, r1, siz) + get(l1, r1 + siz, siz) + get(l1 + siz, r1 + siz, siz);
}

void solve()
{
    cin >> x1 >> x2 >> y11 >> y2;
    cout << get(0, 0, 1 << 20) << '\n';
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