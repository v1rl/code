#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

// 位置的奇偶是不能变的
// 可以在[1, n-3]范围内一定最小
// 3 1 2 4 5
// 2 4 3 1 5
// 2 1 5 4 3

// 奇偶分别存,根据奇偶的逆序对奇偶性来判断是否能达成最优

template<typename T>
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


void solve()
{
    int n;
    cin >> n;
    vector<int> even, odd;
    even.reserve(n);
    odd.reserve(n);
    vector<int> pos(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        if(i & 1) 
        {
            odd.emplace_back(x);
        }
        else 
        {
            even.emplace_back(x);
        }
    }

    Fenwick<int> tr1(n);
    Fenwick<int> tr2(n);
    i64 s1 = 0, s2 = 0;
    for(auto x : even)
    {
        s1 += tr1.rangeSum(x, n);
        tr1.add(x, 1);
    }
    for(auto x : odd)
    {
        s2 += tr2.rangeSum(x, n);
        tr2.add(x, 1);
    }
    
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    if(s1 % 2 != s2 % 2)
    {
        if(n & 1)
        {
            int t = odd.size();
            swap(odd[t - 1], odd[t - 2]);
        }
        else
        {
            int t = even.size();
            swap(even[t - 1], even[t - 2]);
        }
    }
    for(int i = 1; i <= n; i ++)
    {
        if(i & 1) cout << odd[i / 2] << ' ';
        else cout << even[i / 2 - 1] << ' ';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --)
    {
        solve();
    }
    return 0;
} 