#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

struct Crt
{
    vector<int> m;
    vector<int> r;
    Crt(vector<int> &m_, vector<int> &r_) : m(m_), r(r_) {};

    i64 exgcd(i64 a, i64 b, i64 &x, i64 &y)
    {
        if(!b)
        {
            x = 1, y = 0;
            return a;
        }
        i64 t = exgcd(b, a % b, y, x);
        y -= a / b * x;
        return t;
    }

    i64 work()
    {
        int n = m.size();
        i64 M = 1;
        for(auto x : m) M *= x;

        i64 ans = 0;
        for(int i = 0; i < n; i ++)
        {
            i64 x, y;
            i64 t = M / m[i];
            exgcd(t, m[i], x, y);
            ans = (ans + (i128)r[i] * t * x % M) % M;
        }
        return (ans % M + M) % M;
    }
};


int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> m(n);
    vector<int> r(n);
    for(int i = 0; i < n; i ++) 
    {
        cin >> m[i] >> r[i];
    }

    Crt crt(m, r);
    cout << crt.work() << '\n';
}