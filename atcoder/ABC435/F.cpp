#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
题目条件限制下，从当前点向某个方向跳跃后，另一个方向的所有点便不再被考虑了
另外，跳跃的最优落点总是目标方向上小于当前点的最大点
暴力模拟这个跳跃过程即可，因为每次跳跃会舍去另一半，直觉上说应该不会超时
只需要快速查找下标区间中某个数的前驱，用主席树处理即可
*/

template<class Info>
struct PresidentTree {
    int n;
    int idx = 0;
    vector<Info> info;
    PresidentTree(int n_) : n(n_), info(n * (__lg(n) + 2) + 1) {};
    
    void modify(int p, int &q, int l, int r, const int &v) {
        q = ++ idx;
        info[q] = info[p];
        info[q].act ++;
        if(l == r) return;
        int mid = l + r >> 1;
        if(v <= mid) modify(info[p].l, info[q].l, l, mid, v);
        else modify(info[p].r, info[q].r, mid + 1, r, v);
    }

    void modify(int p, int &q, const int &v) {
        modify(p, q, 1, n, v);
    }

    int kth(int p, int q, int l, int r, int k) {
        if(l == r) return l;
        int mid = l + r >> 1;
        int sum = info[info[q].l].act - info[info[p].l].act;
        if(k <= sum) return kth(info[p].l, info[q].l, l, mid, k);
        else return kth(info[p].r, info[q].r, mid + 1, r, k - sum);
    }

    int kth(int p, int q, int k) {
        return kth(p, q, 1, n, k);
    }

    int query(int p, int q, int l, int r, int x, int y) {
        if(r < x || l > y) return 0;
        if(x <= l && y >= r) return info[q].act - info[p].act;
        int mid = l + r >> 1;
        return query(info[p].l, info[q].l, l, mid, x, y) + query(info[p].r, info[q].r, mid + 1, r, x, y);
    }

    int query(int p, int q, int x, int y) {
        return query(p, q, 1, n, x, y);
    }
};

struct Info {
    int l, r;
    int act = 0;
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pos(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    PresidentTree<Info> tr(n);
    vector<int> root(n + 1);
    for(int i = 1; i <= n; i ++) {
        tr.modify(root[i - 1], root[i], a[i]);
    }

    auto prev = [&](int l, int r, int x) {
        int cnt = tr.query(root[l - 1], root[r], 1, x - 1);
        if(cnt == 0) {
            return -1;
        }
        return tr.kth(root[l - 1], root[r], cnt);
    };

    i64 ans = 0;
    i64 res = 0;
    auto dfs = [&](auto &&self, int l, int r, int cur) -> void {
        int mid = pos[cur];

        int nc = prev(l, mid - 1, cur);
        if(nc == -1) {
            ans = max(ans, res);
        } else {
            res += mid - pos[nc];
            self(self, l, mid - 1, nc);
            res -= mid - pos[nc];            
        }

        nc = prev(mid + 1, r, cur);
        if(nc == -1) {
            ans = max(ans, res);
        } else {
            res += pos[nc] - mid;
            self(self, mid + 1, r, nc);            
            res -= pos[nc] - mid;            
        }
    };

    dfs(dfs, 1, n, n);
    cout << ans << '\n';
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
