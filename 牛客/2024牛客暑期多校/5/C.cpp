#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i ++)
    {
        cin >> a[i];
    }
    int l = 0, last = a[l];
    for(int i = 0; i < n; i ++)
    {
        if(a[i] >= last) last = a[i];
        else
        {
            int sum = 0;
            for(int j = l; j < i; j ++)
            {
                sum += a[j];
            }
            int t = sum / (i - l + 1);
            int p = sum % (i - l + 1);
            for(int j = l; j < i; j ++)
            {
                if(p) a[j] = t + 1, p --;
                else a[j] = t;
            }
            l = i;
            last = a[i];
        }
    }
    int sum = 0;
    for(int j = l; j < i; j ++)
    {
        sum += a[j];
    }
    int t = sum / (i - l + 1);
    int p = sum % (i - l + 1);
    for(int j = l; j < i; j ++)
    {
        if(p) a[j] = t + 1, p --;
        else a[j] = t;
    }
    l = i;
    last = a[i];
    

    int ans = 1;
    for(int i = 0; i < n ;i ++)
    {
        ans *= a[i];
    }
    cout << ans << '\n';
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