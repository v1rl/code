#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;
#define pii pair<int,int>

const int mod = 998244353;
const int N=2e5+5;
vector<int> e[N];
bool vis[N];
int dis[N];
int p[N];
int n,s,m;
void init(int n)
{
    for(int i=0;i<=n;i++){
        e[i].clear();
        vis[i]=0;
        dis[i]=1e9;
        p[i]=i;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void join(int x,int y)
{
    p[find(x)]=find(y);
}

void dij(int s)
{
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(find(i)==find(s)){
            dis[i]=0;
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto v:e[u]){
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}
void solve() {
    
    cin>>n>>s>>m;
    init(n);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        if(find(u)!=find(v)) join(u,v);
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int u;
            cin>>u;
            e[find(i)].push_back(find(u));
        }
    }
    dij(s);
    for(int i=1;i<=n;i++){
        dis[find(i)]=min(dis[i],dis[find(i)]);
    }
    for(int i=1;i<=n;i++){
        if(dis[find(i)]==1e9) cout<<-1<<' ';
        else cout<<dis[find(i)]<<' ';
    }
    cout<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --) {
        solve();
    }

    return 0;
}

