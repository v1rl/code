#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for(int i = 1; i <= n; i ++) cin >> a[i], sum += a[i];
    sum /= n;
    int ans = 0;
    for(int i = 1; i < n; i ++)
    {
        a[i] -= sum;
        if(a[i])
        {
            ans ++;
            a[i + 1] += a[i];
        }
    }
    cout << ans << '\n';
}
