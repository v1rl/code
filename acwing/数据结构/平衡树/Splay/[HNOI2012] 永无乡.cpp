#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Info
{
	int s[2], p;
	int siz, val;
}info[1000010];
// int root[100010];
int idx = 0;

int new_node(int val, int p)
{
	int t = ++idx;
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

void splay(int &root, int x, int k)
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

void insert(int &root, int val)
{
	int u = root, p = 0;
	while(u)
	{
		p = u;
		u = info[u].s[val > info[u].val];
	}
	u = new_node(val, p);
	if(p) info[p].s[val > info[p].val] = u;
	splay(root, u, 0);
}

int kth(int &root, int k)
{
	int p = root;
	// if(k > info[p].siz) return -1;
	while(p)
	{
		if(k <= info[info[p].s[0]].siz) p = info[p].s[0];
		else if(k == info[info[p].s[0]].siz + 1) 
		{
			splay(root, p, 0);
			return p;
		}
		else k -= info[info[p].s[0]].siz + 1, p = info[p].s[1];
	}
	return -1;
}

void dfs(int &root, int p)
{
	if(!p) return;
	insert(root, info[p].val);
	dfs(root, info[p].s[0]);
	dfs(root, info[p].s[1]);
}

int p[100010];

int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<int> root(n + 1);
    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i ++)
    {
    	int x;
    	cin >> x;
    	p[i] = i;
    	insert(root[i], x);
    	ans[x] = i;
    }

    while(m --)
    {
    	int x, y;
    	cin >> x >> y;
    	x = find(x), y = find(y);
    	if(x == y) continue;
    	if(info[root[x]].siz < info[root[y]].siz) swap(x, y);
    	dfs(root[x], root[y]);
    	p[y] = x;
    }

    int q;
    cin >> q;
    while(q --)
    {
    	char op;
    	cin >> op;
    	int x, y;
    	cin >> x >> y;
    	if(op == 'Q')
    	{
    		x = find(x);
    		// if(y > info[root[x]].siz) cout << -1 << '\n';
    		// else cout << ans[info[kth(root[x], y)].val] << '\n';
    		int t = kth(root[x], y);
    		cout << (t == -1 ? t : ans[info[t].val]) << '\n';
    	}
    	else
    	{
	    	x = find(x), y = find(y);
	    	if(x == y) continue;
	    	if(info[root[x]].siz < info[root[y]].siz) swap(x, y);
	    	dfs(root[x], root[y]);
	    	p[y] = x;
    	}
    }

    return 0;
}