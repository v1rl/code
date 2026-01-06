#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

// https://codeforces.com/contest/2106/problem/C
// 将题意转化为区间约束，简化代码

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    int l = 0, r = k * 2;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        l = max(l, a[i]);
        r = min(r, a[i] + k);
    }
    for(int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        if(x != -1)
        {
            l = max(l, a[i] + x);
            r = min(r, a[i] + x);
        }
    }
    cout << max(0, r - l + 1) << '\n';
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