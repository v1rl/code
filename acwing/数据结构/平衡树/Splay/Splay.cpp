#include<bits/stdc++.h>
using namespace std; 
using i64 = long long;
const int N = 1e5 + 10;
const int inf = 1e9;
int idx = 0;
struct Info
{
    int s[2], p;
    int siz, val;
    int flag;
}info[N];
int root;
int n, m;

int new_node(int val, int p)
{
    int t = ++ idx;
    info[t].p = p;
    info[t].val = val;
    return idx;
}

void pushup(int p)
{
    info[p].siz = info[info[p].s[0]].siz + info[info[p].s[1]].siz + 1;
}

void pushdown(int p)
{
    if(info[p].flag)
    {
        swap(info[p].s[0], info[p].s[1]);
        info[info[p].s[0]].flag ^= 1;
        info[info[p].s[1]].flag ^= 1;
        info[p].flag = 0;
    }
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

void insert(int val)
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
}

int kth(int k)
{
    int p = root;
    while(1)
    {
        pushdown(p);
        if(info[info[p].s[0]].siz >= k) p = info[p].s[0];
        else if(info[info[p].s[0]].siz + 1 == k) 
        {
            splay(p, 0);
            return p;
        }
        else k -= info[info[p].s[0]].siz + 1, p = info[p].s[1];
    }
    return -1;
}

void output(int p)
{
    // if(!p) return;
    pushdown(p);
    if(info[p].s[0]) output(info[p].s[0]);
    if(info[p].val >= 1 && info[p].val <= n) cout << info[p].val << ' ';
    if(info[p].s[1]) output(info[p].s[1]);
}

void solve()
{
    cin >> n >> m;
    for(int i = 0; i < n + 1; i ++) insert(i);
    for(int i = 0; i < m; i ++)
    {
        int l, r;
        cin >> l >> r;
        l = kth(l), r = kth(r + 2);
        splay(r, 0), splay(l, r);   
        info[info[l].s[1]].flag ^= 1;
    }
    // cerr << 'h';
    output(root);
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