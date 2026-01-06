#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> s(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    vector<int> f(n + 1);
    vector<int> q(n + 1);
    int l = 0, r = 0;
    q[r ++] = 0;
    for(int i = 1; i <= n; i ++)
    {
        f[i] = s[i] - s[q[l]];
        while(l < r && s[q[r - 1]] >= s[i]) r --;
        q[r ++] = i;
        while(l < r && q[r - 1] - q[l] >= m) l ++;
    }
    i64 mx = -1e18;
    for(int i = 1; i <= n; i ++)
        mx = max<i64>(mx, f[i]);
    cout << mx << '\n';
    return 0;
}