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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> day(n + 1);
    vector<int> stt(n + 1);
    vector<int> w(n + 1);
    for(int i = 1; i <= n; i ++) cin >> stt[i];

    i64 sum = 0;
    for(int i = 1; i <= n; i ++)
    {
        int l, r;
        cin >> l >> r;
        sum += 1ll * r * m;
        if(l >= r) continue;
        day[stt[i]].emplace_back(r - l);
    }

    vector<array<int, 2>> q(n + 1);
    int l = 0, r = 0;
    for(int i = 1; i <= m; i ++)
    {
        for(auto x : day[i])
        {
            while(l != r && q[r - 1][1] <= x) r --;
            q[r ++] = {i, x};
            while(i - q[l][0] + 1 > m) l ++;
        }
        sum -= q[l][1];
    }

    cout << sum << '\n';
}

