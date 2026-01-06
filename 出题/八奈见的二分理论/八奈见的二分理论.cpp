#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    while(n --)
    {
        int x;
        cin >> x;
        mp[x] ++;
    }
    vector<int> ans;
    while(m --)
    {
        int x;
        cin >> x;
        if(mp.count(x)) ans.emplace_back(x); 
    }

    sort(ans.begin(), ans.end());
    for(auto x : ans)
    {
        cout << x << ' ';
    }
    // while(n --)
    // {
    //     int x;
    //     cin >> x;
    //     mp[x] ++;
    // }
    // while(m --)
    // {
    //     int x;
    //     cin >> x;
    //     mp[x] ++;
    // }
    // cout << '\n' << '\n';
    // for(auto [num, time] : mp)
    // {
    //     if(time > 1) cout << num << ' ';
    // }
}
