#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];

    vector<int> fl(n + 1, 1);
    vector<int> fr(n + 1, 1);
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j < i; j ++)
        {
            if(a[j] < a[i]) fl[i] = max(fl[i], fl[j] + 1);
        }
    }

    for(int i = n; i; i --)
    {
        for(int j = n; j > i; j --)
        {
            if(a[j] < a[i]) fr[i] = max(fr[i], fr[j] + 1);
        }
    }

    int res = 0;
    for(int i = 1; i <= n; i ++)
    {
        res = max(res, fl[i] + fr[i] - 1);
    }

    cout << n - res << '\n';
    return 0;
}