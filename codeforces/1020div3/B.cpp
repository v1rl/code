#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
        cout << i << ' ';
    for(int i = n - 1; i >= m; i --)
        cout << i << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --)
    {
        solve();
    }
    return 0;
}