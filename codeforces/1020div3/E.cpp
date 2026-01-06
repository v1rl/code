#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9 + 10;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> pos(n + 1);

    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }

    while(q --)
    {
        int l, r, k;
        cin >> l >> r >> k;
        int p = pos[k];
        if(p < l || p > r)
        {
            cout << -1 << ' ';
            continue;
        }
        int bg = 0, lw = 0;
        int nbg = 0, nlw = 0;
        while(1)
        {
            int mid = l + r >> 1;
            if(mid == p) break;
            if(p < mid)
            {
                nbg ++;
                if(a[mid] < k) bg ++;
                r = mid - 1;
            }
            else
            {
                nlw ++;
                if(a[mid] > k) lw ++;
                l = mid + 1;
            }
        }
        if(nlw >= k || nbg > (n - k)) cout << -1 << ' ';
        else cout << max(bg, lw) * 2 << ' ';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --)
    {
        solve();
    }
    return 0;
}