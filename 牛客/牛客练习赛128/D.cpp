#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e6 + 10;
int p[N], siz[N];
int st[N];

int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

unordered_map<string, int> mp;
int cnt = 0;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> state(1000000);
    for(int i = 1; i <= n; i ++)
    {
    	int m;
    	cin >> m;
    	for(int j = 1; j <= m; j ++)
    	{
    		string s;
    		cin >> s;
    		if(!mp.count(s)) mp[s] = cnt ++;
    		int t = mp[s];
    		state[t].emplace_back(i);
    	}
    }

    for(int i = 1; i <= n; i ++) p[i] = i, siz[i] = 1;
    for(int i = 0; i < cnt; i ++)
    {
    	if(state[i].size() > 1)
    	{
    		int x = find(state[i][0]);
	    	for(auto j : state[i])
	    	{
	    		int y = find(j);
	    		if(x == y) continue;
	    		p[y] = x;
	    		siz[x] += siz[y];
	    	}
    	}
    }

    int ans = n;
    for(int i = 1; i <= n; i ++)
    {
    	int t = find(i);
    	if(!st[t])
    	{
    		ans = ans - siz[t] + 1;
    		st[t] = true;
    	}
    }

    // for(int i = 1; i <= n; i ++) cout << i << ' ' << siz[i] << '\n';
    cout << ans << '\n';
}