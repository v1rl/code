#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
const int P = 131;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    unordered_map<int, int> mp;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        mp[a[i]] ++;
    }

    i64 ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        ans += mp[a[i] - m];
    }

    cout << ans << '\n';
    return 0;
}


