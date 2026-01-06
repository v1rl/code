#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];

    vector<int> q(n + 1);
    int l = 0, r = 0;

    for(int i = 1; i <= n; i ++)
    {
        while(l != r && a[q[r - 1]] >= a[i]) r --;
        q[r ++] = i;
        while(q[r - 1] - q[l] + 1 > k) l ++;
        if(q[r - 1] >= k) cout << a[q[l]] << ' ';

    }

    l = 0, r = 0;
    cout << '\n';

    for(int i = 1; i <= n; i ++)
    {
        while(l != r && a[q[r - 1]] <= a[i]) r --;
        q[r ++] = i;
        while(q[r - 1] - q[l] + 1 > k) l ++;
        if(q[r - 1] >= k) cout << a[q[l]] << ' ';
    }
    return 0;

}
