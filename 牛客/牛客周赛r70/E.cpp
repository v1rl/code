#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        int x;
        cin >> x;
        // int ans;
        // if((x / 2) & 1) ans = 1;
        // else ans = 0;
        // if(x % 2 == 0) ans += x;
        // cout << ans << '\n';
        int ans[] = {x, 0, x + 1, 1};
        cout << ans[x % 4] << '\n';
    }
    return 0;
}
