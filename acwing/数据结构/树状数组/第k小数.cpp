#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

template <class T>
struct Fenwick
{
    int n;
    vector<T> a;

    Fenwick(int n_ = 0) : n(n_), a(n + 1) {};

    void add(int x, const T &v)
    {
        for(int i = x; i <= n; i += i & -i)
        {
            a[i] += v;
        }
    }

    T sum(int x)
    {
        T res{};
        for(int i = x; i; i -= i & -i)
        {
            res += a[i];
        }
        return res;
    }

    int select(const T &k)
    {
        int pos = 0;
        T cur{};
        for(int i = 1 << __lg(n); i; i /= 2)
        {
            if(pos + i <= n && cur + a[pos + i] < k)
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
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    Fenwick<int> tr(100000);
    for(int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        tr.add(x, 1);
    }

    while(m --)
    {
        int k;
        cin >> k;
        cout << tr.select(k) + 1 << '\n';
    }

    return 0;
}
