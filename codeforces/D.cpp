#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
void solve()
{
    int n, d, k;
    cin >> n >> d >> k;
    vector<int> stt(n + 1);
    vector<int> edd(n + 1);
    for(int i = 0; i < k; i ++)
    {
        int l, r;
        cin >> l >> r;
        stt[l] ++, edd[r] ++;
    }

    int r = 1;
    int ans = 0;
    int ma = 0;
    int mi = 1e9;
    int pos1, pos2;
    for(int l = 1; l + d - 1 <= n; l ++)
    {
        while(r <= l + d - 1)
        {
            ans += stt[r];
            r ++;
        }
        if(ans > ma)
        {
            ma = ans;
            pos1 = l;
        }
        if(ans < mi)
        {
            mi = ans;
            pos2 = l;
        }
        ans -= edd[l];
    }
    cout << pos1 << ' ' << pos2 << '\n';    
}
*/

void solve()
{
    int n, d, k;
    cin >> n >> d >> k;
    vector<int> c(n + 2);
    for(int i = 0; i < k; i ++)
    {
        int l, r;
        cin >> l >> r;
        l -= d - 1;
        l = max(l, 1);
        c[l] += 1, c[r + 1] -= 1;
    }
    for(int i = 1; i <= n; i ++) c[i] += c[i - 1];


    int mx = 0, imx = -1, mn = 1e9, imn = -1;
    for(int l = 1; l + d - 1 <= n; l ++)
    {
        if(c[l] > mx)
        {
            mx = c[l];
            imx = l;
        }
        if(c[l] < mn)
        {
            mn = c[l];
            imn = l;
        }
    }

    cout << imx << ' ' << imn << '\n';
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