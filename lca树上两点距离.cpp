#include<iostream>
#include<vector>
#include<cstring>
//https://www.acwing.com/file_system/file/content/whole/index/content/9074715/
using namespace std;
const int N=1e5+10;
typedef pair<int,int> PII;
vector<vector<PII>> adj(N);
vector<vector<PII>> query(N);
//vector<PII> adj[N];
//vector<PII> query[N];
int st[N];
int dist[N];
int fa[N];
int n,m;
int ans[N];

int find(int x)
{
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}

void dfs(int x,int p)
{
	for(auto [y,w] : adj[x])
	{
		if(y==p) continue;
		dist[y]=dist[x]+w;
		dfs(y,x);
	}
}

void tarjan(int x)
{
	st[x]=1;
	
	for(auto [y,w] : adj[x])
	{
		if(st[y]) continue;
		tarjan(y);
		fa[y]=x;
	}
	
	for(auto [y,id] : query[x]) 
	{
		if(st[y]==2) 
		{
			int t=find(y);
			ans[id]=dist[x]+dist[y]-dist[t];
		}
	}

	st[x]=2;
}


int main()
{
	cin>>n>>m;
	
	for(int i=1;i<n;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		adj[a].emplace_back(b,w);
		adj[b].emplace_back(a,w);
	}
	
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		query[a].emplace_back(b,i);
		query[b].emplace_back(a,i);
	}
	
	for(int i=1;i<=n;i++) fa[i]=i;
	
	dfs(1,-1);
	tarjan(1);
	
	for(int i=1;i<=m;i++) cout<<ans[i]<<"\n";
}