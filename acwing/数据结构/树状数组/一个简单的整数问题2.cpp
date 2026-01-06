#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

template<typename T>
struct Fenwick
{
    int n;
    vector<T> a;

    Fenwick(int n_ = 0) : n(n_), a(n + 1) {};

    void add(int x, const T &v)
    {
        for(int i = x; i <= n; i += i & -i)
            a[i] += v;
    } 

    T sum(int x)
    {
        T res{};
        for(int i = x; i; i -= i & -i)
            res += a[i];
        return res;
    }

    T rangeSum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    Fenwick<i64> tr1(n + 1), tr2(n + 1);
    vector<i64> sum(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    while(m --)
    {
        char op;
        cin >> op;
        if(op == 'Q')
        {
            int l, r;
            cin >> l >> r;
            i64 rr = tr1.sum(r) * (r + 1) - tr2.sum(r);
            i64 ll = tr1.sum(l - 1) * l - tr2.sum(l - 1);
            cout << sum[r] - sum[l - 1] + rr - ll << '\n';
        }
        else
        {
            int l, r, x;
            cin >> l >> r >> x;
            tr1.add(l, x), tr1.add(r + 1, -x);
            tr2.add(l, x * l), tr2.add(r + 1, -x * (r + 1));
        }
    }
    return 0;
}