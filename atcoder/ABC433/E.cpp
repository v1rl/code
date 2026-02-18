#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
填数构造问题，考虑从限制更强的数到限制更弱的数的思考方式
注意到：本题中“最大值”限制了上界，意味着较大的数限制更强，较小的数限制更弱
所以，从大到小处理是最优解
通过约束条件转换，得到A[i][j] < min(x[i], y[j])
这意味着，当我们在倒序填数，手里的数字是 v 时，只有那些满足 min(x[i], y[j]) > v 的格子是合法的候选位置
注意到：随着 v 减小，满足条件的格子只会越来越多（限制变松），这是一个单调的过程
所以，我们考虑用类似拓扑排序的方式，借助桶，并用队列维护已解锁的格点
同时分类讨论 v 既是行最大又是列最大，只是行最大，既不是行最大也不是列最大三种情况
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    vector<int> px(n * m + 1, -1), py(n * m + 1, -1);
    bool f = true;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(px[a[i]] != -1) {
            f = false;
        }
        px[a[i]] = i;
    }
    for(int i = 0; i < m; i ++) {
        cin >> b[i];
        if(py[b[i]] != -1) {
            f = false;
        }
        py[b[i]] = i;
    }

    if(!f) {
        cout << "No" << '\n';
        return;
    }

    vector<vector<array<int, 2>>> bk(n * m + 1);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            bk[min(a[i], b[j])].push_back({i, j});
        }
    }

    vector g(n, vector(m, 0));
    queue<array<int, 2>> q;

    for(int i = n * m; i >= 1; i --) {
        if(px[i] != -1 && py[i] != -1) {
            g[px[i]][py[i]] = i;
            for(auto [x, y] : bk[i]) {
                if(x == px[i] && y == py[i]) {
                    continue;
                }
                q.push({x, y});
            }
        } else if(px[i] != -1 || py[i] != -1) {
            if(bk[i].empty()) {
                cout << "No" << '\n';
                return;
            }
            g[bk[i][0][0]][bk[i][0][1]] = i;
            for(int j = 1; j < bk[i].size(); j ++) {
                q.push({bk[i][j][0], bk[i][j][1]});
            }
        } else {
            if(q.empty()) {
                cout << "No" << '\n';
                return;
            }
            auto [x, y] = q.front();
            q.pop();
            g[x][y] = i;
        }
    }

    cout << "Yes" << '\n';
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cout << g[i][j] << " \n"[j == m - 1];
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}