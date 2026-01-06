#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9, N = 5e5 + 10;
int root;

struct Info
{
	int s[2];
	int siz, p, val;
	int sum, ls, rs, ms;
	bool rev, same;
}info[N];
int nodes[N], cnt = 0;
int a[N];
int w[N];

void new_node(int &u, int val, int p)
{
	u = nodes[cnt --];
	info[u].s[0] = info[u].s[1] = 0;
	info[u].rev = info[u].same = 0;
	info[u].siz = 1, info[u].p = p;
	info[u].val = info[u].sum = info[u].ms = val;
	info[u].ls = info[u].rs = max(0, val);
}

void pushup(int x)
{
	auto &p = info[x], &l = info[info[x].s[0]], &r = info[info[x].s[1]];
	p.siz = l.siz + r.siz + 1;
	p.sum = l.sum + r.sum + p.val;
	p.ls = max(l.ls, l.sum + p.val + r.ls);
	p.rs = max(r.rs, r.sum + p.val + l.rs);
	p.ms = max({l.ms, r.ms, l.rs + p.val + r.ls});
}

void pushdown(int x)
{
	auto &p = info[x], &l = info[info[x].s[0]], &r = info[info[x].s[1]];
	if(p.same)
	{
		p.same = p.rev = 0;
		int val = p.val;
		if(p.s[0])
		{
			l.same = 1, l.val = val, l.sum = val * l.siz;
			if(val > 0) l.ms = l.ls = l.rs = l.sum;
			else l.ms = val, l.ls = l.rs = 0;
		}
		if(p.s[1])
		{
			r.same = 1, r.val = val, r.sum = val * r.siz;
			if(val > 0) r.ms = r.ls = r.rs = r.sum;
			else r.ms = val, r.ls = r.rs = 0;
		}
	}
	if(p.rev)
	{
		p.rev = 0, l.rev ^= 1, r.rev ^= 1;
		swap(l.ls, l.rs), swap(r.rs, r.ls);
		swap(l.s[0], l.s[1]), swap(r.s[0], r.s[1]);
	}
}

void build(int &u, int l, int r, int p)
{
	int mid = l + r >> 1;
	if(l > r) return;
	new_node(u, w[mid], p);
	if(l == r) return;
	build(info[u].s[0], l, mid - 1, u);
	build(info[u].s[1], mid + 1, r, u);
	pushup(u);
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

int kth(int k)
{
	int p = root;
	while(p)
	{
		pushdown(p);
		if(k <= info[info[p].s[0]].siz) p = info[p].s[0];
		else if(k == info[info[p].s[0]].siz + 1) 
		{
			return p;
			splay(p, 0);
		}
		else k -= info[info[p].s[0]].siz + 1, p = info[p].s[1];
	}
	return -1;
}

void dfs(int p)
{
	if(!p) return;
	nodes[++ cnt] = p;
	dfs(info[p].s[0]);
	dfs(info[p].s[1]);
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;

		int p = n;

	for(int i = 1; i < N; i ++) 
		nodes[++ cnt] = i;
	for(int i = 1; i <= n; i ++)
		cin >> w[i];
	info[0].ms = w[0] = -inf, w[n + 1] = -inf;
	build(root, 0, n + 1, 0);

	while(m --)
	{
		string op;
		cin >> op;
		if(op == "INSERT")
		{
			int pos, tot;
			cin >> pos >> tot;

				p += tot;

			for(int i = 1; i <= tot; i ++)
				cin >> w[i];
			int l = kth(pos + 1), r = kth(pos + 2);
			splay(l, 0), splay(r, l);
			build(info[r].s[0], 1, tot, r);
			pushup(r), pushup(l);
		}
		else if(op == "DELETE")
		{
			int pos, tot;
			cin >> pos >> tot;
			int l = kth(pos), r = kth(pos + tot + 1);
			splay(l, 0), splay(r, l);
			dfs(info[r].s[0]);
			info[r].s[0] = 0;
			pushup(r), pushup(l);
		}
		else if(op == "MAKE-SAME")
		{
			int pos, tot, c;
			cin >> pos >> tot >> c;
			int l = kth(pos), r = kth(pos + tot + 1);
			splay(l, 0), splay(r, l);
			auto &son = info[info[r].s[0]];
			son.same = 1, son.val = c, son.sum = c * son.siz;
			if(c > 0) son.ms = son.ls = son.rs = son.sum;
			else son.ms = c, son.ls = son.rs = 0;
			pushup(r), pushup(l);
		}
		else if(op == "REVERSE")
		{
			int pos, tot;
			cin >> pos >> tot;
			int l = kth(pos), r = kth(pos + tot + 1);
			splay(l, 0), splay(r, l);
			auto &son = info[info[r].s[0]];
			son.rev ^= 1;
			swap(son.s[0], son.s[1]);
			swap(son.ls, son.rs);
			pushup(r), pushup(l);
		}
		else if(op == "GET-SUM")
		{
			int pos, tot;
			cin >> pos >> tot;
			int l = kth(pos), r = kth(pos + tot + 1);
			splay(l, 0), splay(r, l);
			cout << info[info[r].s[0]].sum << '\n';
		}
		else
		{
			cout << info[root].ms << '\n';
		}
	}
	return 0;
}