#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<array<int, 2>> dat(n);
    for(int i = 0; i < n; i ++)
    {
        int x, y;
        cin >> x >> y;
        dat[i] = {x, y};
    }

    sort(dat.begin(), dat.end());

    vector<int> sel;
    sel.reserve(n);
    int cnt = 0;
    for(int i = 0; i < n; i ++)
    {
        int pos = lower_bound(sel.begin(), sel.end(), dat[i][1]) - sel.begin();
        if(pos == cnt)
        {
            sel.emplace_back(dat[i][1]);
            cnt ++;
        }
        else sel[pos] = dat[i][1];
    }

    cout << cnt << '\n';
    return 0;
}