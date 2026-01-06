#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i ++) cin >> a[i];

        int sum = 0;
        int ans = 0;
        for(auto t : a)
        {
            if(t >= k) sum += t;
            else if(t == 0 && sum > 0)
            {
                ans ++;
                sum -= 1;
            }
        }
        cout << ans << '\n';
    }
}