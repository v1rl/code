#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

void solve()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
    {
        if((i & (n - 1)) == i) cout << k << ' ';
        else cout << 0 << ' '; 
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        solve();
    }
}