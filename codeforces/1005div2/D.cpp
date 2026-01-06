#include<bits/stdc++.h>
using namespace std; 
using i64 = long long;
const int inf = 1e9 + 10;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), pre(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
    }

    vector<array<int, 30>> f(n + 1);

    for(int i = 1; i <= n; i ++)
    {
        f[i] = f[i - 1];
        int pos = __lg(a[i]);
        for(int j = 0; j <= pos; j ++)
            f[i][j] = i;
    }

    while(q --)
    {
        int x;
        cin >> x;

        int cur = n;
        while(1)
        {
            if(x == 0) break;
            int msb = __lg(x);
            int nxt = f[cur][msb];

            // cout << x << ' ' << msb << ' ' << nxt << '\n';
            x ^= pre[cur] ^ pre[nxt];

            cur = nxt;
            if(nxt == 0 || a[nxt] > x) break;
            x ^= a[nxt];

            cur --;
        }

        cout << n - cur << ' ';
    }
    cout << '\n';
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