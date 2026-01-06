#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 2e6 + 10;
const int inf = 2147483647;

struct Info
{
    int s[2], p;
    int siz, val;
}info[N];;

template<class Info>
struct Splay
{
    int n;
    int idx = 0;

    void new_node(int &u, int val, int p)
    {
        u = ++ idx;
        info[u].p = p;
        info[u].val = val;
        info[u].siz = 1;        //注意变量名
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
        new_node(u, val, p);
        if(p) info[p].s[val > info[p].val] = u;
        splay(root, u, 0);
    }

    void remove(int &root, int val)
    {
        int p = root;
        while(p)
        {
            if(val < info[p].val) p = info[p].s[0];
            else if(val == info[p].val) break;
            else p = info[p].s[1];
        }
        splay(root, p, 0);                      //取子节点前要先把当前点提到根
        int l = info[p].s[0], r = info[p].s[1];
        while(info[l].s[1]) l = info[l].s[1];
        while(info[r].s[0]) r = info[r].s[0];
        splay(root, l, 0), splay(root, r, l);
        info[r].s[0] = 0;
        pushup(r), pushup(l);
    }

    int pre(int root, int val)
    {
        int p = root, res;
        while(p)
        {
            if(val <= info[p].val) p = info[p].s[0];
            else
            {
                res = info[p].val;
                p = info[p].s[1];
            }
        }
        return res;
    }

    int suf(int root, int val)
    {
        int p = root, res;
        while(p)
        {
            if(val >= info[p].val) p = info[p].s[1];
            else
            {
                res = info[p].val;
                p = info[p].s[0];
            }
        }
        return res;
    }

    int rank(int root, int val)
    {
        int p = root, res = 0;
        while(p)
        {
            if(val <= info[p].val) p = info[p].s[0];
            // else if(val == info[p].val)              //不能直接加，因为左子节点中可能存在与当前点val相等的点
            // {
            //     res += info[info[p].s[0]].siz;
            //     break;
            // }
            else
            {
                res += info[info[p].s[0]].siz + 1;
                p = info[p].s[1];
            }
        }
        return res - 1;             //减去哨兵节点
    }
};

struct Segmentree
{
    int n;
    vector<int> root;
    Splay<Info> tr;
    Segmentree(int n_, vector<int> &a) : n(n_), root(4 * n)
    {
        function<void(int, int, int)> build = [&](int p, int l, int r)
        {
            tr.insert(root[p], -inf);
            tr.insert(root[p], inf);
            for(int i = l; i <= r; i ++)            //线段树建树时将序列加入平衡树
                tr.insert(root[p], a[i]);
            if(l == r) return;
            int mid = l + r >> 1;
            build(p << 1, l, mid);
            build(p << 1 | 1, mid + 1, r);
        };
        build(1, 1, n);
    };

    void modify(int p, int l, int r, int pos, int x, int op)
    {
        if(op) tr.insert(root[p], x);
        else tr.remove(root[p], x);
        if(l == r) return;
        int mid = l + r >> 1;
        if(pos <= mid) modify(p << 1, l, mid, pos, x, op);
        else modify(p << 1 | 1, mid + 1, r, pos, x, op);
    }

    void modify(int pos, int x, int op)
    {
        modify(1, 1, n, pos, x, op);
    }

    int pre(int p, int l, int r, int x, int y, int k)
    {
        if(r < x || l > y) return -inf;
        if(x <= l && r <= y) return tr.pre(root[p], k);
        int mid = l + r >> 1;
        return max(pre(p << 1, l, mid, x, y, k), pre(p << 1 | 1, mid + 1, r, x, y, k));
    }

    int pre(int x, int y, int k)
    {
        return pre(1, 1, n, x, y, k);
    }

    int suf(int p, int l, int r, int x, int y, int k)
    {
        if(r < x || l > y) return inf;
        if(x <= l && r <= y) return tr.suf(root[p], k);
        int mid = l + r >> 1;
        return min(suf(p << 1, l, mid, x, y, k), suf(p << 1 | 1, mid + 1, r, x, y, k));
    }

    int suf(int x, int y, int k)
    {
        return suf(1, 1, n, x, y, k);
    }

    int rank(int p, int l, int r, int x, int y, int val)
    {
        if(r < x || l > y) return 0;
        if(x <= l && r <= y) return tr.rank(root[p], val);
        int mid = l + r >> 1;
        return rank(p << 1, l, mid, x, y, val) + rank(p << 1 | 1, mid + 1, r, x, y, val);        
    }

    int rank(int x, int y, int val)
    {
        return rank(1, 1, n, x, y, val) + 1;
    }

    int kth(int x, int y, int k)
    {
        auto check = [&](int val)
        {
            int pos = rank(x, y, val);
            return k >= pos;
        };

        int l = 0, r = 1e8;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(check(mid)) l = mid;
            else r = mid - 1;
        }

        return l;
    }
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    Segmentree tr(n, a);
    while(m --)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int l, r, k;
            cin >> l >> r >> k;
            cout << tr.rank(l, r, k) << '\n';
        }
        else if(op == 2)
        {
            int l, r, k;
            cin >> l >> r >> k;
            cout << tr.kth(l, r, k) << '\n';
        }
        else if(op == 3)
        {
            int pos, k;
            cin >> pos >> k;
            tr.modify(pos, a[pos], 0);
            tr.modify(pos, k, 1);
            a[pos] = k;
        }
        else if(op == 4)
        {
            int l, r, k;
            cin >> l >> r >> k;
            cout << tr.pre(l, r, k) << '\n';
        }
        else
        {
            int l, r, k;
            cin >> l >> r >> k;
            cout << tr.suf(l, r, k) << '\n';
        }
    }
    return 0;
}