#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct dat
{
    string s1;
    int w;
    string s2;
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    string stt;
    int n;
    cin >> stt >> n;
    unordered_map<string, int> mp;
    vector<dat> info(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        string s1, s2;
        int w;
        cin >> s1 >> w >> s2;
        mp[s1] = i;
        info[i] = {s1, w, s2};
    }

    int h = -1;
    vector<int> ne(n + 1, -1);
    for(int i = 1; i <= n; i ++)
    {
        auto &[s1, w, s2] = info[i];
        if(s1 == stt) h = i;
        if(s2 != "-1") ne[i] = mp[s2];
    }

    vector<int> s(n + 1);
    int idx = 0;
    for(int i = h; i != -1; i = ne[i])
    {
        s[++ idx] = i;
    }

    for(int i = 1, j = idx, cnt = 1; cnt <= idx; cnt ++)
    {
        int x, y;
        if(cnt & 1) x = j, j --, y = i;
        else x = i, i ++, y = j;
        cout << info[s[x]].s1 << ' ' << info[s[x]].w << ' ';
        if(cnt != idx) cout << info[s[y]].s1 << '\n';
        else cout << -1 << '\n';
    }

    return 0;
}