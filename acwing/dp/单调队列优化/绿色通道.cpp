#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
        cin >> a[i];

    auto check = [&](int x)
    {
        x ++;
        vector<int> f(n + 1);
        vector<int> q(n + 1);
        int l = 0, r = 0;
        q[r ++] = 0;
        for(int i = 1; i <= n; i ++)
        {
            while(l < r && i - q[l] > x) l ++;
            f[i] = f[q[l]] + a[i];
            while(l < r && f[i] <= f[q[r - 1]]) r --;
            q[r ++] = i;
        }
        if(l < r && n - q[l] + 1 > x) l ++;
        return f[q[l]] <= k;
    };

    int l = 0, r = n;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}