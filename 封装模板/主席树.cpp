#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

template<class Info>
struct PresidentTree {
    int n;
    int idx = 0;
    vector<Info> info;
    PresidentTree(int n_) : n(n_), info(n * (__lg(n) + 2) + 1) {};
    PresidentTree(int n_, int cnt_) : n(n_), info(cnt_ * (__lg(n) + 2) + 1) {};
    
    void modify(int p, int &q, int l, int r, const int &v, const int &add = 0) {
        q = ++ idx;
        info[q] = info[p];
        info[q].act ++;
        info[q].sum += add;
        if(l == r) return;
        int mid = l + r >> 1;
        if(v <= mid) modify(info[p].l, info[q].l, l, mid, v, add);
        else modify(info[p].r, info[q].r, mid + 1, r, v, add);
    }

    void modify(int p, int &q, const int &v, const int &add = 0) {
        modify(p, q, 1, n, v, add);
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

    int queryC(int p, int q, int l, int r, int x, int y) {
        if(l > y || r < x) return 0;
        if(l >= x && r <= y) return info[q].act - info[p].act;
        int mid = l + r >> 1;
        return queryC(info[p].l, info[q].l, l, mid, x, y) + queryC(info[p].r, info[q].r, mid + 1, r, x, y);
    }

    int queryC(int p, int q, int x, int y) {
        return queryC(p, q, 1, n, x, y);
    }

    i64 queryS(int p, int q, int l, int r, int x, int y) {
        if(l > y || r < x) return 0;
        if(l >= x && r <= y) return info[q].sum - info[p].sum;
        int mid = l + r >> 1;
        return queryS(info[p].l, info[q].l, l, mid, x, y) + queryS(info[p].r, info[q].r, mid + 1, r, x, y);
    }

    i64 queryS(int p, int q, int x, int y) {
        return queryS(p, q, 1, n, x, y);
    }
};

struct Info {
    int l, r;
    int act = 0;
    i64 sum = 0;
};

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    vector<int> kth;
    kth.reserve(n);

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        kth.emplace_back(a[i]);
    }

    sort(kth.begin(), kth.end());
    kth.erase(unique(kth.begin(), kth.end()), kth.end());
    int S = kth.size();

    auto rank = [&](int x) {
        return lower_bound(kth.begin(), kth.end(), x) - kth.begin() + 1;
    };

    for(int i = 1; i <= n; i ++) {
        a[i] = rank(a[i]);
    }

    PresidentTree<Info> tr(n);
    vector<int> root(n + 1);
    for(int i = 1; i <= n; i ++) {
        tr.modify(root[i - 1], root[i], a[i]);
    }

    auto prev = [&](int l, int r, int x) {
        int cnt = tr.queryC(root[l - 1], root[r], 1, x - 1);
        if(cnt == 0) {
            return -1;
        }
        return tr.kth(root[l - 1], root[r], cnt);
    };

    auto net = [&](int l, int r, int x) {
        int cnt = tr.queryC(root[l - 1], root[r], 1, x);
        int tot = tr.queryC(root[l - 1], root[r], 1, S);
        if(cnt == tot) {
            return -1;
        }
        return tr.kth(root[l - 1], root[r], cnt + 1);
    };

    while(q --) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << kth[tr.kth(root[l - 1], root[r], k) - 1] << '\n';
    }
}