#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    vector<int> f(n + 1);
    vector<int> q(n + 1);
    int l = 0, r = 0;
    q[r ++] = 0;
    for(int i = 1; i <= n; i ++)
    {
        while(l < r && i - q[l] > m) l ++;
        f[i] = f[q[l]] + a[i];
        while(l < r && f[i] <= f[q[r - 1]]) r --;
        q[r ++] = i;
    }
    if(l < r && n - q[l] + 1 > m) l ++;
    cout << f[q[l]] << '\n';
}