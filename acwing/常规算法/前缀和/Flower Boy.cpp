#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9 + 10;

// https://codeforces.com/contest/2106/problem/D
// 前缀后缀预处理，处理到b数组的某一位时a数组的最小位置
// 可以删除某一位，于是比较前缀i-1与后缀i+1

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> pre(m + 1, n + 2), suf(m + 2, -1);
    pre[0] = 0;
    suf[m + 1] = n + 1;

    vector<int> a(n + 1);
    vector<int> b(m + 1);
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    for(int i = 1; i <= m; i ++)
        cin >> b[i];

    for(int i = 1, k = 1; i <= n; i ++)
    {
        if(a[i] >= b[k])
        {
            pre[k] = i;
            k ++;
        }
        if(k == m + 1) break;
    }
    for(int i = n, k = m; i >= 1; i --)
    {
        if(a[i] >= b[k])
        {
            suf[k] = i;
            k --;
        }
        if(k == 0) break;
    }

    if(pre[m] != n + 2)
    {
        cout << 0 << '\n';
        return;
    }

    int ans = inf;
    for(int i = 1; i <= m; i ++)
    {
        if(pre[i - 1] < suf[i + 1])
        {
            ans = min(ans, b[i]);
        }
    }
    cout << (ans == inf ? -1 : ans) << '\n';
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