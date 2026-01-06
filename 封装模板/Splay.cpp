#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9, N = 5e5 + 10;
template<class Info, class Tag>
struct Splay
{
    int n;
    int root;
    vector<Info> info;
    vector<Tag> tag;
    vector<int> nodes;
    int cnt = 0;

    Splay(int n_) : n(n_), info(n + 1), tag(n + 1), nodes(n + 1)
    {
        for(int i = 1; i <= n; i ++) 
            nodes[++ cnt] = i;
        info[0].ms = -inf;
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

    void apply(int p, const Tag &t)
    {
        tag[p].apply(t);
        info[p].apply(t);
    }

    void pushdown(int p)
    {
        if(info[p].s[0]) apply(info[p].s[0], tag[p]);       //平衡树pushdown的节点可能不存在子节点，要先判断子节点是否存在
        if(info[p].s[1]) apply(info[p].s[1], tag[p]);
        tag[p] = Tag{};
    }

    void new_node(int &u, int val, int p)
    {
        u = nodes[cnt --];
        info[u].siz = 1, info[u].p = p;
        info[u].val = info[u].sum = info[u].ms = val;
        info[u].ls = info[u].rs = max(0, val);
    }

    void build(int &u, int l, int r, int p, vector<int> &w)
    {
        if(l > r) return;       //可能出现l > r
        int mid = l + r >> 1;
        new_node(u, w[mid], p);
        // if(l == r) return;
        build(info[u].s[0], l, mid - 1, u, w);      //mid已被处理，进一步递归[l, mid - 1]与[mid + 1, r]
        build(info[u].s[1], mid + 1, r, u, w);
        pushup(u);                              //建完点后向上更新
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
            pushdown(p);            //查找前先pushdown
            if(k <= info[info[p].s[0]].siz) p = info[p].s[0];
            else if(k == info[info[p].s[0]].siz + 1)
            {
                splay(p, 0);        //查找也要splay
                return p;
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
        tag[p] = Tag{};             //回收节点时，将节点内容清空
        info[p] = Info();
    }

    void insert(int pos, vector<int> &w)
    {
        int tot = w.size();
        int l = kth(pos + 1), r = kth(pos + 2);
        splay(l, 0), splay(r, l);
        build(info[r].s[0], 0, tot - 1, r, w);      //注意父节点为r
        pushup(r), pushup(l);
    }

    void remove(int pos, int tot)
    {
        int l = kth(pos), r = kth(pos + tot + 1);
        splay(l, 0), splay(r, l);
        dfs(info[r].s[0]);
        info[r].s[0] = 0;
        pushup(r), pushup(l);
    }

    void makesame(int pos, int tot, const Tag &t)
    {
        int l = kth(pos), r = kth(pos + tot + 1);
        splay(l, 0), splay(r, l);
        apply(info[r].s[0], t);
        pushup(r), pushup(l);
    }

    void reverse(int pos, int tot, const Tag &t)
    {
        int l = kth(pos), r = kth(pos + tot + 1);
        splay(l, 0), splay(r, l);
        apply(info[r].s[0], t);
        pushup(r), pushup(l);
    }

    int get_sum(int pos, int tot)
    {
        int l = kth(pos), r = kth(pos + tot + 1);
        splay(l, 0), splay(r, l);
        return info[info[r].s[0]].sum;
    }

    int get_max()
    {
        return info[root].ms;
    }
};

struct Tag
{
    bool rev = false, same = false;
    int val = inf;

    void apply(const Tag &t)
    {
        rev ^= t.rev;
        same |= t.same;         //注意懒标记的更新方式
        if(t.val != inf) val = t.val;
    }
};

struct Info
{
    int s[2], p, siz;
    int val, sum, ls, rs, ms;

    void apply(const Tag &t)
    {
        if(t.same)
        {
            val = t.val, sum = val * siz;
            if(val > 0) ms = ls = rs = sum;
            else ms = val, ls = rs = 0;
        }
        if(t.rev)
        {
            swap(ls, rs);
            swap(s[0], s[1]);
        }
    }
};


int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;

    Splay<Info, Tag> tr(5e5);
    vector<int> w(n + 2);
    w[0] = w[n + 1] = -inf;         //哨兵点
    for(int i = 1; i <= n; i ++)
        cin >> w[i];

    tr.build(tr.root, 0, n + 1, 0, w);

    while(m --)
    {
        string op;
        cin >> op;
        if(op == "INSERT")
        {
            int pos, tot;
            cin >> pos >> tot;
            vector<int> w(tot);
            for(int i = 0; i < tot; i ++)
                cin >> w[i];
            tr.insert(pos, w);
        }
        else if(op == "DELETE")
        {
            int pos, tot;
            cin >> pos >> tot;
            tr.remove(pos, tot);
        }
        else if(op == "MAKE-SAME")
        {
            int pos, tot, c;
            cin >> pos >> tot >> c;
            tr.makesame(pos, tot, {0, 1, c});
        }
        else if(op == "REVERSE")
        {
            int pos, tot;
            cin >> pos >> tot;
            tr.reverse(pos, tot, {1});
        }
        else if(op == "GET-SUM")
        {
            int pos, tot;
            cin >> pos >> tot;
            cout << tr.get_sum(pos, tot) << '\n';
        }
        else
        {
            cout << tr.get_max() << '\n';
        }
    }
    return 0;
}