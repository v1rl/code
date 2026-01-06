#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

template<class T>
struct RMQ
{
    int n;
    vector<T> a;
    vector<vector<T>> stmax;
    RMQ(int n_, vector<T> &a_) : n(n_), a(a_), stmax(n + 1)
    {
        for(int i = 1; i <= n ; i++)
        {
            stmax[i].resize(21, 0);
        }
        init();
    }

    void init()
    {
        for(int i = 1; i <= n; i ++) stmax[i][0] = a[i];
        for(int j = 1; (1 << j) <= n; j ++)
        {   
            for(int i = 1; i <= n - (1 << j) + 1; i ++)
            {
                stmax[i][j] = max(stmax[i][j - 1], stmax[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T askmax(int l, int r)
    {
        int len = log2(r - l + 1);
        return max(stmax[l][len], stmax[r - (1 << len) + 1][len]);
    }
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    RMQ<int> rmq(n, a);
    while(q --)
    {
        int l, r;
        cin >> l >> r;
        cout << rmq.askmax(l, r) << '\n';
    }
    return 0;
}