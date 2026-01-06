#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
// 借助同一行中一定选取排在最后面的那一个这一性质，优化掉了矩阵行列中的一个(一般为列)
// 细化的dp的属性
// 矩阵转置 反向定位 博弈论的重复子问题dp 属性为矩阵的占据情况

void solve()
{
    int l, n, m;
    cin >> l >> n >> m;
    vector<int> a(l + 1);
    for(int i = 1; i <= l; i ++) cin >> a[i];
    vector b(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            cin >> b[i][j];

    if(n > m)
    {
        swap(n, m);
        vector c(n + 1, vector<int>(m + 1));
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= m; j ++)
                c[i][j] = b[j][i];

        swap(b, c);
    }

    vector<vector<array<int, 2>>> vec(n * m + 1);
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
        {
            vec[b[i][j]].push_back({i, j});
        }

    // 选手以a[i]作为先手时，在可以赢的情况下，在第r行所能占据的(最大)列数
    vector f(l + 2, vector<int>(m + 2));
    for(int i = l; i >= 1; i --)
        for(int j = n; j >= 1; j --)
        {
            f[i][j] = f[i][j + 1];
            auto it = lower_bound(vec[a[i]].begin(), vec[a[i]].end(), array{j + 1, 0});
            if(it == vec[a[i]].begin()) continue;
            it --;
            if((*it)[0] == j && (*it)[1] >= f[i + 1][j + 1])    //比较行数时，与下一行比较，比较列数时，相等也可
            {
                f[i][j] = max(f[i][j], (*it)[1]);
            }
        }

    // vector<int> f(n + 2);
    // for (int i = l; i >= 1; i --) {
    //     int u = 0;
    //     for (int r = n; r >= 1; r--) {
    //         auto it = std::lower_bound(vec[a[i]].begin(), vec[a[i]].end(), std::array {r + 1, 0});
    //         int v = r == n ? 0 : f[r + 1];
    //         if (it != vec[a[i]].begin()) {
    //             it--;
    //             if ((*it)[0] == r && (*it)[1] >= u) {
    //                 v = std::max(v, (*it)[1]);
    //             }
    //         }
    //         u = f[r];
    //         f[r] = v;
    //     }
    // }

    if(f[1][1] > 0) cout << 'T' << '\n';
    // if(f[1] > 0) cout << 'T' << '\n';
    else cout << 'N' << '\n';
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
}