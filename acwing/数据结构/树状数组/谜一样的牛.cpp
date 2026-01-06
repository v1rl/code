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

    int select(const T &k)              // 前缀和小于等于 k 的最大下标位置
    {
        int pos = 0;
        T cur{};
        for(int i = 1 << __lg(n); i; i >>= 1)
        {
            if(pos + i <= n && cur + a[pos + i] <= k)
            {
                cur += a[pos + i];
                pos += i;
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
    for(int i = 2; i <= n; i ++) 
        cin >> a[i];

    Fenwick<int> tr(n);
    for(int i = 1; i <= n; i ++)
        tr.add(i, 1);

    vector<int> ans(n + 1);
    for(int i = n; i; i --)
    {
        ans[i] = tr.select(a[i]) + 1;
        tr.add(ans[i], -1);
    }

    for(int i = 1; i <= n; i ++)
        cout << ans[i] << '\n';
}