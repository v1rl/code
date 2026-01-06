#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i ++) cin >> a[i];

    int ans = 0;
    for(int i = 1; i < (1 << m); i ++)
    {
        int res = 1, cnt = 0;
        for(int j = 0; j < m; j ++)
        {
            if(i >> j & 1)
            {
                res *= a[j];
                cnt ++;
            }
        }
        if(cnt & 1) ans += n / res;
        else  ans -= n / res;
    }

    cout << ans << '\n';
}