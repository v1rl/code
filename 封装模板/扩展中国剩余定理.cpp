#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

struct Excrt
{
    vector<i64> r;
    vector<i64> m;

    Excrt(vector<i64> &r, vector<i64> &m) : r(r), m(m) {};

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

    i64 qmul(i64 a, i64 b, i64 mod)
    {
        i64 res = 0;
        while(b)
        {
            if(b & 1) res = (res + a) % mod;
            a = (a + a) % mod;
            b >>= 1;
        }
        return res;
    }

    i64 lcm(i64 a, i64 b)
    {
        return a / __gcd(a, b) * b;
    }

    i64 work()
    {
        i64 ansr, ansm;
        int n = r.size();
        for(int i = 0; i < n; i ++)
        {
            if(i == 0)
            {
                ansr = r[i];
                ansm = m[i];
            }
            else
            {
                i64 x, y;
                i64 gcd = exgcd(ansm, m[i], x, y);
                i64 R = ((r[i] - ansr) % m[i] + m[i]) % m[i];
                if(R % gcd)
                {
                    return -1;
                }
                else
                {
                    x = qmul(x, R / gcd, m[i] / gcd);
                    ansr += x * ansm;
                    ansm = lcm(ansm, m[i]);
                    ansr = (ansr % ansm + ansm) % ansm;
                }
            }
        }
        return ansr;
    }
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<i64> r(n);
    vector<i64> m(n);
    for(int i = 0; i < n; i ++)
    {
        cin >> m[i] >> r[i];
    }
    Excrt excrt(r, m);
    cout << excrt.work() << '\n';
}