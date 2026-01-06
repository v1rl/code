#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 210, M = 10010;
int h[N], ne[M], v[M];
i64 f[M];
int dist[N];
int n, m, stt, edd, idx;
int cur[N];

void add(int x, int y, int w)
{
    v[idx] = y, f[idx] = w, ne[idx] = h[x], h[x] = idx ++;
}

bool bfs()
{
    queue<int> q;
    memset(dist, -1, sizeof dist);
    dist[stt] = 0, cur[stt] = h[stt];
    q.push(stt);
    while(q.size())
    {
        int x = q.front();
        q.pop();
        for(int i = h[x]; ~i; i = ne[i])
        {
            int y = v[i];
            if(dist[y] != -1) continue;
            if(f[i] == 0) continue;
            dist[y] = dist[x] + 1;
            cur[y] = h[y];
            if(y == edd) return true;
            q.push(y);
        }
    }
    return false;
}

i64 find(int x, i64 limit)
{
    if(x == edd) return limit;
    i64 flow = limit;
    for(int i = cur[x]; ~i && flow > 0; i = ne[i])
    {
        cur[x] = i; 
        int y = v[i]; 
        if(dist[y] == dist[x] + 1 && f[i])
        {
            i64 t = find(y, min(f[i], flow));
            if(!t) dist[y] = -1;
            f[i] -= t, f[i ^ 1] += t, flow -= t;
        }
    }
    return limit - flow;
}

i64 dinic()
{
    i64 res = 0, flow;
    while(bfs()) 
    {
        while(flow = find(stt, 1e18)) 
        {
            res += flow;
        }
    }
    return res;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m >> stt >> edd;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i ++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        add(x, y, w);
        add(y, x, 0);
    }

    cout << dinic() << '\n';
}