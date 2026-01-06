#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 210, M = 10010;
int h[N], v[M], ne[M];
i64 f[M], dist[N];
int pre[N];
bool st[N];
int n, m, stt, edd, idx;

void add(int x, int y, int w)
{
    v[idx] = y, f[idx] = w, ne[idx] = h[x], h[x] = idx ++;
}

bool bfs()
{
    queue<int> q;
    memset(st, false, sizeof st);
    q.push(stt);
    dist[stt] = 1e9, st[stt] = true;
    while(q.size())
    {
        int x = q.front();
        q.pop();
        for(int i = h[x]; ~i; i = ne[i])
        {
            int y = v[i];
            if(f[i] == 0) continue;
            if(st[y]) continue;
            st[y] = true;
            dist[y] = min(dist[x], f[i]);
            pre[y] = i;
            if(y == edd) return true;
            q.push(y);
        }
    }
    return false;
}

i64 EK()
{
    i64 res = 0;
    while(bfs())
    {
        res += dist[edd];
        for(int i = edd; i != stt; i = v[pre[i] ^ 1])
        {
            f[pre[i]] -= dist[edd];
            f[pre[i] ^ 1] += dist[edd];
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m >> stt >> edd;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= m; i ++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        add(x, y, w);
        add(y, x, 0);
    }

    cout << EK() << '\n';
    return 0;
}