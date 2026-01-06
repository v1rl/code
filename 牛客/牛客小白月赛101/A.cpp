#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<i64> s(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        cin >> s[i];
        s[i] += s[i - 1];
    }

    i64 ans = 0;
    int len = n - m;
    for(int i = len; i <= n; i ++)
        ans = max(ans, s[i] - s[i - len]);

    cout << ans << '\n';
}