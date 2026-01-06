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
        for(int i = 1; i <= n; i++)
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
            for(int i = 1; i + (1 << j) - 1 <= n; i ++)
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
    vector<i64> sum(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    vector<i64> res(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        res[i] = a[i] - sum[i - 1];
    }
    RMQ<i64> rmq(n, res);
    while(q --)
    {
        int l, r;
        cin >> l >> r;
        if(l == r)
        {
            cout << 0 << '\n';
            continue;
        }
        cout << max(0ll, rmq.askmax(l + 1, r) + sum[l - 1]) << '\n';
    }
}