#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<i64> a(n + 1);
    i64 sum = 0;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    i64 ave = accumulate(a.begin() + 1, a.end(), 0ll) / n;
    for(int i = 1; i <= n; i ++) a[i] -= ave;
    for(int i = 1; i <= n; i ++) a[i] += a[i - 1];
    sort(a.begin() + 1, a.end());
    int z = a[(n + 1) / 2];
    i64 ans = 0;
    for(int i = 1; i <= n; i ++) ans += abs(a[i] - z);
    cout << ans << '\n';
}
