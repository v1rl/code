#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
整体移动地图反过来，就相当于移动人所在的起点
于是，我们可以通过跑该起点的dfs得到目标结果所需的最短步数
此时会发现，难以判断当前情况是否已经满足垃圾全清的条件

注意到：最终仍然有效的区块一定是一个区间
因此，我们可以考虑在bfs的同时维护这样的剩余区间
剩余区间是否存在垃圾，则直接累加该区间的所有"#"的个数即可，这一点可以用二维前缀和优化

这样的区间应该怎么维护呢，通常会想到考虑维护六个变量[lx, rx, ly, ry, tx, ty]，前四个表示剩余区间，最后两个表示当前人的坐标
通过一点小小的模拟会发现，每次移动后不好去维护[lx, rx, ly, ry]，因为每次都会让前四个变量加一个偏移量，
这个偏移量有正有负，且需要保证前四个变量始终位于规定的矩形范围内
我们考虑将后两个变量换成矩形范围的一个端点
为避免移动过程中出现负数，我们取右端点
这样，每次移动后，我们就不需要在原来的基础上加偏移量，而是直接根据已移动距离来判断边界
相应的，人的坐标则由原右端点和现右端点相减计算得到

第二种方法，考虑到范围不大，可以利用哈希(map<vector<string>>, int>)存储当前图的情况和对应步数
并在bfs时不断更新，超出部分不管，其余部分补'.'
最后判断是否有全部是'.'的图即可
// https://atcoder.jp/contests/abc427/submissions/70035934
*/

const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n, vector(m, '.'));
    vector pre(n + 1, vector(m + 1, 0));
    int tx, ty;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> g[i][j];
            if(g[i][j] == 'T') {
                tx = i, ty = j;
            }
            pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] - pre[i][j] + (g[i][j] == '#');
        }
    }

    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
    queue<array<int, 6>> q;
    q.push({0, n, 0, m, n, m});

    vector dist(n + 1, vector(n + 1, vector(m + 1, vector(m + 1, vector(n * 2 + 1, vector(m * 2 + 1, inf))))));
    dist[0][n][0][m][n][m] = 0;

    while(q.size()) {
        auto [lx, rx, ly, ry, cx, cy] = q.front();
        q.pop();
        if(pre[rx][ry] - pre[lx][ry] - pre[rx][ly] + pre[lx][ly] == 0) {
            cout << dist[lx][rx][ly][ry][cx][cy] << '\n';
            return;
        }

        for(int i = 0; i < 4; i ++) {
            int nlx, nrx, nly, nry, ncx, ncy;
            ncx = cx + dx[i];
            ncy = cy + dy[i];
            nlx = max(lx, ncx - n);
            nrx = min(rx, ncx);
            nly = max(ly, ncy - m);
            nry = min(ry, ncy);

            if(ncx < 0 || ncx > 2 * n || ncy < 0 || ncy > 2 * m) {
                continue;
            }
            int X = tx + ncx - n, Y = ty + ncy - m;
            if(X >= nlx && X < nrx && Y >= nly && Y < nry && g[X][Y] == '#') {
                continue;
            }
            if(dist[nlx][nrx][nly][nry][ncx][ncy] > dist[lx][rx][ly][ry][cx][cy] + 1) {
                dist[nlx][nrx][nly][nry][ncx][ncy] = dist[lx][rx][ly][ry][cx][cy] + 1;
                q.push({nlx, nrx, nly, nry, ncx, ncy});
            }
        }
    }

    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
