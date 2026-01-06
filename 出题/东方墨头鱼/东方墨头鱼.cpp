#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    while(n --)
    {
        int x;
        cin >> x;
        // int l = 0, r = cnt;
        // while(l < r)
        // {
        //    int mid = l + r >> 1;
        //    if(a[mid] <= x) r = mid;
        //    else l = mid + 1;
        // }
        // a[l] = x;
        // if(l == cnt) cnt ++;
        
        int pos = upper_bound(a.begin(), a.begin() + cnt, x, greater<int>()) - a.begin();
        a[pos] = x;
        if(pos == cnt) cnt ++;

        // int pos = cnt;
        // for(int i = 0; i < cnt; i ++)
        // {
        //     if(a[i] <= x)
        //     {
        //         pos = i;
        //         break;
        //     }
        // }
        // a[pos] = x;
        // if(pos == cnt) cnt ++;
    }
    cout << cnt << '\n';
    for(int i = 0; i < cnt; i ++) cout << a[i] << ' ';
    return 0;
}