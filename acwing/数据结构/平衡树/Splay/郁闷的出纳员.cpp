#include<bits/stdc++.h>
using namespace std; 
using i64 = long long;
const int N = 1e5 + 10;
const int inf = 1e9;

struct Info
{
    int s[2], p;
    int siz, val;
}info[N];
int root;
int idx = 0;

int new_node(int val, int p)
{
    int t = ++ idx;
    info[t].siz = 1;
    info[t].val = val;
    info[t].p = p;
    return t;
}

void pushup(int p)
{
    info[p].siz = info[info[p].s[0]].siz + info[info[p].s[1]].siz + 1;
}

void rotate(int x)
{
    int y = info[x].p, z = info[y].p;
    int xy = x == info[y].s[1];
    int yz = y == info[z].s[1];
    info[z].s[yz] = x, info[x].p = z;
    info[y].s[xy] = info[x].s[xy ^ 1], info[info[x].s[xy ^ 1]].p = y;
    info[x].s[xy ^ 1] = y, info[y].p = x;
    pushup(y), pushup(x);
}

void splay(int x, int k)
{
    while(info[x].p != k)
    {
        int y = info[x].p, z = info[y].p;
        if(z != k)
        {
            if((x == info[y].s[1]) ^ (y == info[z].s[1])) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
    if(!k) root = x;
}

int insert(int val)
{
    int u = root, p = 0;
    while(u)
    {
        p = u;
        u = info[u].s[val > info[u].val];
    }
    u = new_node(val, p);
    if(p) info[p].s[val > info[p].val] = u;
    splay(u, 0);
    return u;
}

int suf(int val)
{
    int p = root, res = 0;
    int f = 0;
    while(p)
    {
        f = p;
        if(val <= info[p].val)
        {
            res = p;
            p = info[p].s[0];
        }
        else p = info[p].s[1];
    }
    splay(f, 0);
    return res;
}

int kth(int k)
{
    int p = root;
    while(p)
    {
        if(k <= info[info[p].s[0]].siz) p = info[p].s[0];
        else if(k == info[info[p].s[0]].siz + 1) 
        {
            splay(p, 0);
            return p;
        }
        else k -= info[info[p].s[0]].siz + 1, p = info[p].s[1];
    }
    return -1;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int l = insert(-inf), r = insert(inf);
    int d = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i ++)
    {
        char op;
        int x;
        cin >> op >> x;
        if(op == 'I') 
        {
            if(x >= m) insert(x - d), cnt ++;
        }
        else if(op == 'A') d += x;
        else if(op == 'S') 
        {
            d -= x;
            r = suf(m - d);
            splay(r, 0), splay(l, r);
            info[l].s[1] = 0;
            pushup(l), pushup(r);
        }
        else
        {
            int siz = info[root].siz;
            int k = siz - x;
            if(k <= 1) cout << -1 << '\n';
            else cout << info[kth(k)].val + d << '\n';
        }
    }
    cout << cnt - (info[root].siz - 2) << '\n';
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