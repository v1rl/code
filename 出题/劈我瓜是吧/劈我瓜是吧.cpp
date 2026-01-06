#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    if(m >= n + 1 && m <= 1ll * n * (n + 1) / 2 + 1)
    {
        cout << "YES" << '\n';
        int total = m - 1;
        int cnt = n;
        int base = 0;
        while(total - cnt >= 0)
        {
            total -= cnt;
            cnt --;
            base ++;
        }
        for(int i = 1; i <= n; i ++)
        {
            if(base >= i) cout << i << ' ';
            else if(total > 0) cout << base + 1 << ' ', total --;
            else cout << base << ' ';
        }
    }
    else cout << "NO" << '\n';
    return 0;
}
