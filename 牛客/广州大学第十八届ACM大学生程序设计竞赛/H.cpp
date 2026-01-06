#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

void solve()
{
    unordered_map<int, char> mp;
    mp[1] = 'l', mp[2] = 'z', mp[3] = 'e', mp[4] = 'a', mp[5] = 's', mp[6] = 'b', mp[7] = 't', mp[9] = 'g', mp[0] = 'o';
    string s;
    getline(cin, s);
    for(auto c : s)
    {
        if(c >= '0' && c <= '9')
            cout << mp[c - '0'];
        else cout << c;
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t --)
    {
        solve();
    }
    return 0;
}

