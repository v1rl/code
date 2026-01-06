#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

template<class T>
struct Fenwick
{
    int n;
    vector<T> a;
    Fenwick(int n_) : n(n_), a(n + 1) {};

    void add(int x, const T &v)
    {
        for(int i = x; i <= n; i += i & -i)
            a[i] += v;
    }

    int select(const T &k)
    {
        int pos = 0;
        T cur{};
        for(int i = 1 << __lg(n); i; i >>= 1)
        {
            if(pos + i <= n && cur + a[pos + i] <= k)
            {
                pos += i;
                cur += a[pos];
            }
        }
        return pos;
    }
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    Fenwick<int> tr(n);
    for(int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        tr.add(i, x);
    }
    int q;
    cin >> q;
    while(q --)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int pos, x;
            cin >> pos >> x;
            tr.add(pos, x);
        }
        else
        {
            int k;
            cin >> k;
            cout << tr.select(k) << '\n';
        }
    }
    return 0;
}