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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    Fenwick<int> tr1(n), tr2(n);
    vector<int> l(n + 1), r(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        tr1.add(a[i], 1);
        l[i] = tr1.sum(a[i] - 1);
    }
    for(int i = n; i; i --)
    {
        tr2.add(a[i], 1);
        r[i] = tr2.sum(a[i] - 1);
    }

    i64 res1 = 0, res2 = 0;
    for(int i = 1; i <= n; i ++)
    {
        res1 += 1ll * l[i] * r[i];
        res2 += 1ll * (i - l[i] - 1) * (n - i + 1 - r[i] - 1);
    }

    cout << res2 << ' ' << res1 << '\n';
    return 0;

}