#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

typedef array<i64, 3> AL3;

const i64 inf = 1e18;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<AL3>> adj(n + 1);
    for(int i = 0; i < m; i ++) {
        int x, y, c, w;
        cin >> x >> y >> c >> w;
        adj[x].push_back({y, c, w});
        adj[y].push_back({x, c, w});
    }

    vector<int> color(k + 1), limit(k + 1);
    vector<vector<int>> pos(m + 1), val(m + 1);
    for(int i = 1; i <= k; i ++) {
        cin >> color[i] >> limit[i];
        pos[color[i]].emplace_back(i);
        val[color[i]].emplace_back(limit[i]);
    }

    vector<int> lg(k + 1);
    for(int i = 2; i <= k; i ++) {
        lg[i] = lg[i >> 1] + 1;
    }

    vector<vector<vector<int>>> stmax(m + 1);

    auto init = [&](auto &stmax, int p, int K, int M) -> void {
        stmax[0] = val[p];
        for(int i = 1; i < K; i ++) {
            int len = 1 << i;
            int half = len >> 1;
            for(int j = 0; j + len <= M; j ++) {
                stmax[i][j] = max(stmax[i - 1][j], stmax[i - 1][j + half]);
            }
        }
    };

    for(int i = 1; i <= m; i ++) {
        int M = pos[i].size();
        int K = lg[M] + 1;
        stmax[i].assign(K, vector<int>(M, 0));

        init(stmax[i], i, K, M);
    }

    auto queryMax = [&](int c, int l, int r) {
        int i = lg[r - l + 1];
        return max(stmax[c][i][l], stmax[c][i][r - (1 << i) + 1]);
    };

    auto get = [&](int curC, int curR, int w) {
        int P = upper_bound(pos[curC].begin(), pos[curC].end(), curR) - pos[curC].begin();
        if(P == pos[curC].size()) {
            return -1;
        }

        int l = P, r = pos[curC].size();
        if(queryMax(curC, l, r - 1) < w) {
            return -1;
        }

        while(l < r) {
            int mid = l + r >> 1;
            if(queryMax(curC, P, mid) >= w) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if(l != pos[curC].size()) {
            return pos[curC][l];
        }
        return -1;
    };

    priority_queue<AL3, vector<AL3>, greater<AL3>> heap;
    vector<i64> R(n + 1, inf);
    vector<i64> U(n + 1, inf);
    R[1] = 1, U[1] = 0;
    heap.push({R[1], U[1], 1});

    vector<int> ans(n + 1);

    while(heap.size()) {
        auto [r, u, x] = heap.top();
        heap.pop();
        if(r != R[x] || (r == R[x] && u != U[x])) {
            continue;
        }
        ans[x] = 1;

        for(auto [y, c, w] : adj[x]) {
            if(c == color[r] && u + w <= limit[r]) {
                if(r < R[y] || (r == R[y] && u + w < U[y])) {
                    R[y] = r, U[y] = u + w;
                    heap.push({R[y], U[y], y});
                }
            } 

            int jpR = get(c, r, w);
            if(jpR != -1) {
                if(jpR < R[y] || (jpR == R[y] && w < U[y])) {
                    R[y] = jpR, U[y] = w;
                    heap.push({R[y], U[y], y});
                }
            }
        }
    }

    for(int i = 1; i <= n; i ++) {
        cout << ans[i];
    }
    cout << '\n';
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