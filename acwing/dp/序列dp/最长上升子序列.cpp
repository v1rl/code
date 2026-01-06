#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;

    vector<int> f(n + 1, 1);
    vector<int> a(n + 1);
    int ans = 0;

    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        for(int j = 1; j < i; j ++)
        {
            if(a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
        }
        ans = max(ans, f[i]);
    }
    
    cout << ans << '\n';
    return 0;
}