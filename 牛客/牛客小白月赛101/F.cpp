#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244353;

void solve()
{
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < n; i ++) cin >> b[i];

    set<int> S;
    int r = 0;
    int num = 0;
    i64 res = 1;
    for(int l = 0; l < n; l ++)
    {
        while(r <= min(l + w, n - 1))
        {
            if(a[r] != -1) S.insert(a[r]);
            else num ++;
            r ++;
        }

        if(!S.count(b[l]))
        {
            if(num > 0) res = res * num % mod, num --;
            else
            {
                cout << 0 << '\n';
                return;
            }
        }
    }

    cout << res << '\n';
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