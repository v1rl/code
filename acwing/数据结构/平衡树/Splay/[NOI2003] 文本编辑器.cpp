#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 4e6 + 10;

struct Info
{
	int s[2], p;
	char val;
	int siz;
}info[N];

char s[100];
char t[N];

struct Splay
{
	int n;
	int root = 0;
	int idx = 0;

	void new_node(int &u, char val, int p)
	{
		if(!u) u = ++ idx;
		info[u].val = val;
		info[u].siz = 1;
		info[u].p = p;
	}

	Splay()
	{
		t[0] = t[1] = 'a';
		build(root, 0, 1, 0);
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

	void build(int &u, int l, int r, int p)
	{
		if(l > r) return;
		int mid = l + r >> 1;
		new_node(u, t[mid], p);
		build(info[u].s[0], l, mid - 1, u);
		build(info[u].s[1], mid + 1, r, u);
		pushup(u);
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

	void insert(int pos, int tot)
	{
		int l = kth(pos + 1), r = kth(pos + 2);
		splay(l, 0), splay(r, l);
		build(info[r].s[0], 0, tot - 1, r);
		pushup(r), pushup(l);
	}

	void remove(int pos, int tot)
	{
		int l = kth(pos), r = kth(pos + tot + 1);
		splay(l, 0), splay(r, l);
		info[r].s[0] = 0;
		pushup(r), pushup(l);
	}

	void output(int p)
	{
		if(!p) return;
		output(info[p].s[0]);
		printf("%c", info[p].val);
		output(info[p].s[1]);
	}

	void out(int pos, int tot)
	{
		int l = kth(pos), r = kth(pos + tot + 1);
		splay(l, 0), splay(r, l);
		output(info[r].s[0]);
		printf("\n");
	}
};

int main()
{
	int n;
	scanf("%d", &n);
	Splay tr;
	int pos = 1;				//令pos表示当前所处字符的位置
	for(int i = 1; i <= n; i ++)
	{
		scanf("%s", s);
		if(s[0] == 'I')
		{
			int m;
			scanf("%d", &m);
			for(int i = 0; i < m; i ++)
			{
				t[i] = getchar();
				if(t[i] == '\n' || t[i] == '\r') i --;
			}
			// getchar();
			tr.insert(pos - 1, m);				//insert表示在pos后接入，题意要求插入在pos位置，因此pos要先-1
		}
		else if(s[0] == 'M')
		{
			int k;
			scanf("%d", &k);
			pos = k + 1;			//移动到第pos个字符后，因此要+1
		}
		else if(s[0] == 'D')
		{
			int tot;
			scanf("%d", &tot);
			tr.remove(pos, tot);
		}
		else if(s[0] == 'G')
		{
			int tot;
			scanf("%d", &tot);
			tr.out(pos, tot);
		}
		else if(s[0] == 'P') pos --;
		else pos ++;
	}
	return 0;
}