#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i ++) cin >> arr[i];

    map<int, int> mp;
    int cnt = 0;
    vector<vector<int>> state(n);
    for(int i = 0; i < n; i ++)
    {
        if(!mp.count(arr[i])) mp[arr[i]] = cnt ++;
        int t = mp[arr[i]];
        state[t].emplace_back(i);
    }

    vector<int> f(n);
    f[0] = 0;
    vector<bool> st(n);
    vector<bool> visit(cnt);
    queue<int> q;
    q.push(0);
    st[0] = true;

    while(q.size())
    {
        int x = q.front();
        q.pop();
        int y = x - 1;
        if(y >= 0 && !st[y])
        {
            st[y] = true;
            f[y] = f[x] + 1;
            q.push(y);
        }
        y = x + 1;   
        if(y < n && !st[y])
        {
            st[y] = true;
            f[y] = f[x] + 1;
            q.push(y);
        }

        int t = mp[arr[x]];
        if(visit[t]) continue;
        for(auto y : state[t])
        {
            if(st[y]) continue;
            st[y] = true;
            q.push(y);
            f[y] = f[x] + 1;
        }
        visit[t] = true;
    }
    cout << f[n - 1] << '\n';
}