#include<bits/stdc++.h>
using namespace std; 
using i64 = long long;
const int inf = 1e9 + 10;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), num(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        num[a[i]] ++;
    }

    int wl = -1, wr = -1;
    int ansl = -1, ansr = -1;
    int len = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(num[a[i]] == 1)
        {
            if(wl == -1)
            {
                wl = wr = i;
            }
            else wr ++;
        }
        else
        {
            if(wl != -1)
            {
                if(wr - wl + 1 > len)
                {
                    len = wr - wl;
                    ansl = wl;
                    ansr = wr;
                }
                wl = wr = -1;
            }
        }
    }
    if(wl != -1)
    {
        if(wr - wl + 1 > len)
        {
            len = wr - wl;
            ansl = wl;
            ansr = wr;
        }
    }
    if(ansl != -1)
    {
        cout << ansl << ' ' << ansr << '\n';
    }
    else cout << 0 << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    // t = 1;
    while(t --)
    {
        solve();
    }
    return 0;
}