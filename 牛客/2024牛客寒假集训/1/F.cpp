#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;
// f[元素值映射后得到的值]————当前元素值在当前范围中出现的次数
// cnt[前缀和得到的值]————当前范围内，值等于当前值的前缀和下标个数

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];

    auto c = a;
    sort(c.begin() + 1, c.end());
    for(int i = 1; i <= n; i ++)
    {
        a[i] = lower_bound(c.begin() + 1, c.end(), a[i]) - c.begin();
    }

    vector<int> t(n + 1);
    t[1] = 1;
    for(int i = 2; i <= n; i ++)
    {
        if(a[i] == a[i - 1]) t[i] = t[i - 1];
        else t[i] = -t[i - 1];
    }

    vector<int> pre(n + 1);
    pre[0] = n;
    for(int i = 1; i <= n; i ++)
    {
        pre[i] = pre[i - 1] + t[i];
    }

    vector<int> cnt(2 * n + 1);
    vector<int> f(n + 1);
    int ans = 0;
    int dist = 0;
    for(int l = 1, r = 1; r <= n; r ++)
    {
        // cerr << 'h';
        cnt[pre[r - 1]] ++;

        dist += (f[a[r]]++ == 0);
        while(dist > 2)
        {
            dist -= (--f[a[l]] == 0);
            cnt[pre[l - 1]] --;
            l ++;
        }

        ans += cnt[pre[r]];
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        solve();
    }
}