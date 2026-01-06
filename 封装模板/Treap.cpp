#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
const int inf = 1e9;

struct Info
{
    int l = 0, r = 0;
    int val, w;
    int siz, cnt;
};
int idx = 0;

template<typename Info>
struct Treap
{
    int n;
    vector<Info> info;
    int idx = 0;
    int root;

    int new_node(int val)
    {
        info[++idx].val = val;
        info[idx].w = rand();
        info[idx].siz = info[idx].cnt = 1;
        return idx;
    }

    Treap(int n_) : n(n_), info(n + 3)
    {
        init();
    };

    void init()
    {
        root = new_node(-inf);
        info[root].r = new_node(inf);
        pushup(root);
    }

    void pushup(int p)
    {
        info[p].siz = info[info[p].l].siz + info[info[p].r].siz + info[p].cnt;
    }

    void lrotate(int &p)
    {
        int q = info[p].r;
        info[p].r = info[q].l, info[q].l = p;
        p = q;
        pushup(info[p].l), pushup(p);
    }

    void rrotate(int &p)
    {
        int q = info[p].l;
        info[p].l = info[q].r, info[q].r = p;
        p = q;
        pushup(info[p].r), pushup(p);
    }

    void insert(int &p, int x)
    {
        if(!p)
        {
            p = new_node(x);
            return;
        }
        if(x == info[p].val)
        {
            info[p].cnt ++, info[p].siz ++;
            return;
        }
        if(x < info[p].val)
        {
            insert(info[p].l, x);
            if(info[info[p].l].w > info[p].w) rrotate(p);
        }
        else
        {
            insert(info[p].r, x);
            if(info[info[p].r].w > info[p].w) lrotate(p);
        }
        pushup(p);
    }

    void insert(int x)
    {
        insert(root, x);
    }

    void remove(int &p, int x)
    {
        if(!p) return;
        if(x == info[p].val)
        {
            if(info[p].cnt > 1)
            {
                info[p].cnt --, info[p].siz --;
                return;
            }
            if(!info[p].l && !info[p].r)
            {
                p = 0;
                return;
            }
            if(!info[p].l || info[info[p].r].w > info[info[p].l].w)
            {
                lrotate(p);
                remove(info[p].l, x);
            }
            else
            {
                rrotate(p);
                remove(info[p].r, x);
            }
        }
        else if(x < info[p].val) remove(info[p].l, x);
        else remove(info[p].r, x);
        pushup(p);
    }

    void remove(int x)
    {
        remove(root, x);
    }

    int get_rank(int p, int x)
    {
        if(!p) return 1;
        if(x == info[p].val) return info[info[p].l].siz + 1;
        if(x < info[p].val) return get_rank(info[p].l, x);
        return info[info[p].l].siz + info[p].cnt + get_rank(info[p].r, x);
    }

    int get_rank(int x)
    {
        return get_rank(root, x);
    }

    int get_val(int p, int k)
    {
        if(!p) return inf;
        if(k <= info[info[p].l].siz) return get_val(info[p].l, k);
        if(k <= info[info[p].l].siz + info[p].cnt) return info[p].val;
        return get_val(info[p].r, k - info[info[p].l].siz - info[p].cnt);
    }

    int get_val(int k)
    {
        return get_val(root, k);
    }

    int get_pre(int p, int x)
    {
        if(!p) return -inf;
        if(info[p].val >= x) return get_pre(info[p].l, x);
        return max(info[p].val, get_pre(info[p].r, x));
    }

    int get_pre(int x)
    {
        return get_pre(root, x);
    }

    int get_sub(int p, int x)
    {
        if(!p) return inf;
        if(info[p].val <= x) return get_sub(info[p].r, x);
        return min(info[p].val, get_sub(info[p].l, x));
    }

    int get_sub(int x)
    {
        return get_sub(root, x);
    }
};

void solve()
{
    int n;
    cin >> n;
    Treap<Info> tr(n);
    while(n --)
    {
        int op, x;
        cin >> op >> x;
        if(op == 1)
            tr.insert(x);
        else if(op == 2)
            tr.remove(x);
        else if(op == 3)
            cout << tr.get_rank(x) - 1 << '\n';
        else if(op == 4)
            cout << tr.get_val(x + 1) << '\n';
        else if(op == 5)
            cout << tr.get_pre(x) << '\n';
        else
            cout << tr.get_sub(x) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    t = 1;
    while(t --)
    {
        solve();
    }
}