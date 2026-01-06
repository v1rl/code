#include<iostream>
#include<vector>
#include<cstring>
//https://www.luogu.com.cn/problem/P3379
using namespace std;
const int N=5e5+10;
typedef pair<int,int> PII;
vector<vector<int>> adj(N);
vector<vector<PII>> query(N);
int st[N];
int fa[N];
int n,m;
int ans[N];

int find(int x)
{
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}

void tarjan(int x)
{
	st[x]=1;
	
	for(auto y : adj[x])
	{
		if(st[y]) continue;
		tarjan(y);
		fa[y]=x;
	}
	
	for(auto [y,id] : query[x]) 
	{
		if(st[y]==2) ans[id]=find(y);
	}

	st[x]=2;
}


int main()
{
	int s;
	cin>>n>>m>>s;
	
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		if(a==b) ans[i]=a;
		else
		{
			query[a].emplace_back(b,i);
			query[b].emplace_back(a,i);
		}
	}
	
	for(int i=1;i<=n;i++) fa[i]=i;
	
	tarjan(s);
	
	for(int i=1;i<=m;i++) cout<<ans[i]<<"\n";
}