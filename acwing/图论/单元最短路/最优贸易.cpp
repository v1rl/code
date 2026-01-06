#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> w(n + 1);
    for(int i = 1; i <= n; i ++) cin >> w[i];
    vector<vector<int>> adj1(n + 1);
	vector<vector<int>> adj2(n + 1);
    for(int i = 0; i < m; i ++)
    {
    	int x, y, op;
    	cin >> x >> y >> op;
    	adj1[x].emplace_back(y);
    	adj2[y].emplace_back(x);
    	if(op == 2) adj1[y].emplace_back(x), adj2[x].emplace_back(y);
    }

    vector<int> dist1(n + 1, 1e9);
    vector<int> dist2(n + 1, 0);
    vector<bool> st(n + 1);
    queue<int> q;

    q.push(1);
    st[1] = true;
    dist1[1] = w[1]; 
    while(q.size())
    {
    	int x = q.front();
    	q.pop();
    	st[x] = false;
    	for(auto y : adj1[x])
    	{
    		if(dist1[y] > min(dist1[x], w[y]))
    		{
    			dist1[y] = min(dist1[x], w[y]);
    			if(!st[y]) st[y] = true, q.push(y);
    		}
    	}
    }

    st.assign(n + 1, false);
    q.push(n);
    st[1] = true;
    dist2[n] = w[n];
    while(q.size())
    {
    	int x = q.front();
    	q.pop();
    	st[x] = false;
    	for(auto y : adj2[x])
    	{
    		if(dist2[y] < max(dist2[x], w[y]))
    		{
    			dist2[y] = max(dist2[x], w[y]);
    			if(!st[y]) st[y] = true, q.push(y);
    		}
    	}
    }

    int ans = 0;
    for(int i = 1; i <= n; i ++)
    {
    	ans = max(ans, dist2[i] - dist1[i]);
    }
    cout << ans << '\n';
}