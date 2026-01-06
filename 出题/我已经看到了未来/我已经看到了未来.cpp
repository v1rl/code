#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> dat(n);
    int x, y;
    cin >> x >> y;
    for(int i = 0; i < n; i ++) cin >> dat[i];


    sort(dat.begin(), dat.end());
    int pos = lower_bound(dat.begin(), dat.end(), x) - dat.begin();
    int l, r;

    if(pos == n) 
    {
        l = r = pos = n - 1;
        while(l >= 0 && dat[l] == dat[r]) l --;
        l ++;
    }
    else if(dat[pos] == x)
    {
        l = r = pos;
        while(r < n && dat[r] == dat[l]) r ++;
        r --;
    }
    else if(dat[pos] != x)
    {
        if(pos - 1 >= 0 && x - dat[pos - 1] < dat[pos] - x)
        {
            l = r = pos - 1;
            while(l >= 0 && dat[l] == dat[r]) l --;
            l ++;            
        }
        else if(pos - 1 >= 0 && x - dat[pos - 1] == dat[pos] - x)
        {
            l = r = pos - 1;
            while(l >= 0 && dat[l] == dat[r]) l --;
            l ++;

            int ll = ++ r;
            while(r < n && dat[r] == dat[ll]) r ++;
            r --; 
        }
        else
        {
            l = r = pos;
            while(r < n && dat[l] == dat[r]) r ++;
            r --;            
        }
    }

    int ans;
    ans = max(l, y);
    ans = min(r, ans);
    cout << ans + 1 << '\n';
    return 0; 
}
