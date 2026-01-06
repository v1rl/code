#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n * 2 + 1), b(n * 2 + 1);
    vector<int> s(n * 2 + 1);
    vector<i64> pre(n * 2 + 1), suf(n * 2 + 2);
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i] >> b[i];
        s[i] = s[i + n] = a[i] - b[i];
    }

    for(int i = 1; i <= 2 * n; i ++)
        pre[i] = pre[i - 1] + s[i];

    b[0] = b[n];
    for(int i = 1; i <= n; i ++)
        s[i] = s[i + n] = a[i] - b[i - 1];

    for(int i = 2 * n; i; i --)
        suf[i] = suf[i + 1] + s[i];

    vector<int> q(2 * n + 2);
    vector<int> st(n + 1);
    int l = 0, r = 0;
    for(int i = 1; i <= 2 * n; i ++)
    {
        while(l < r && i - q[l] > n) l ++;
        if(i > n)
        {
            if(pre[q[l]] - pre[i - n - 1] >= 0) st[i - n] = true;
        }
        while(l < r && pre[i] <= pre[q[r - 1]]) r --;
        q[r ++] = i;
    }

    l = 0, r = 0;
    for(int i = 2 * n; i; i --)
    {
        while(l < r && q[l] - i > n) l ++;
        if(i <= n)
        {
            if(suf[q[l]] - suf[i + n + 1] >= 0) st[i] = true;
        }
        while(l < r && suf[i] <= suf[q[r - 1]]) r --;
        q[r ++] = i;
    }

    for(int i = 1; i <= n; i ++)
    {
        if(st[i]) cout << "TAK" << '\n';
        else cout << "NIE" << '\n';
    }
    return 0;
}