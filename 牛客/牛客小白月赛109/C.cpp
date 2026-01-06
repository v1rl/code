#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int ceil(int n, int m)
{
    return (n + m - 1) / m;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
    int idx = 0;
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> range(ceil(n, 100));
    range[0] ++;
    while(q --)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int l, r;
            cin >> l >> r;
            int gl = l / 100, gr = r / 100;
            for(int i = gl; i <= gr; i ++)
            {
                if(range[i] == 100)
                {
                    // cout << 'h';
                    continue;
                }
                for(int j = max(l, i * 100); j <= min(r, (i + 1) * 100 - 1); j ++)
                {
                    if(a[j]) continue;
                    a[j] = ++ idx;
                    range[i] ++;
                }
            } 
        }
        else
        {
            int x;
            cin >> x;
            cout << a[x] << '\n';
        }
    }
    return 0;
}

