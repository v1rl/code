#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Info
{
    char op1;
    int x1;
    char op2;
    int x2;
};

void solve()
{
    int n;
    cin >> n;

    vector<Info> query(n + 1);

    for(int i = 1; i <= n; i ++)
    {
        char op1, op2;
        int x1, x2;
        cin >> op1 >> x1 >> op2 >> x2;
        query[i] = {op1, x1, op2, x2};
    }

    i64 res1 = 1, res2 = 1;
    int l = 1, r = 2;
    auto work = [&](i64 &res)
    {
        while(l < r)
        {
            auto [op1, x1, op2, x2] = query[l];
            i64 t = 0;
            if(op1 == '+') t += res1 + x1;
            else t += res1 * x1;
            if(op2 == '+') t += res2 + x2;
            else t += res2 * x2;
            i64 z = t - res1 - res2;
            res += z;
            l ++;
        }
    };

    while(r <= n)
    {
        auto [op1, x1, op2, x2] = query[r];
        if((op1 == 'x' && op2 == '+') || (op1 == 'x' && op2 == 'x' && x1 > x2))
            work(res1);
        else if((op1 == '+' && op2 == 'x') || (op1 == 'x' && op2 == 'x' && x1 < x2))
            work(res2);
        r ++;
    }
    work(res1);
    cout << res1 + res2 << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        solve();
    }
    return 0;
}