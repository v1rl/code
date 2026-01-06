#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> map(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        map[x] = i;
    }
    
    vector<int> a(n);
    for(int i = 0; i < n; i ++)
    {
        int x;
        cin >> x;
        a[i] = map[x];
    }

    vector<int> g(n);
    int cnt = 0;
    for(int i = 0; i < n; i ++)
    {
        int pos = lower_bound(g.begin(), g.begin() + cnt, a[i]) - g.begin();
        g[pos] = a[i];
        if(pos == cnt) cnt ++;
    }
    cout << cnt << '\n';
    return 0;
}