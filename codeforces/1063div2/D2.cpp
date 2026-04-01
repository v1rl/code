#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int inf = 1e9;

int query(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<array<int, 2>> qry(q);
    for(int i = 0; i < q; i ++) {
        int l, r;
        cin >> l >> r;
        qry[i] = {l, r};
    }

    {
        sort(qry.begin(), qry.end());
        vector<array<int, 2>> nqry;
        for (auto [l, r] : qry) {
            if (!nqry.empty() && r <= nqry.back()[1]) {
                continue;
            }
            nqry.push_back({l, r});
        }
        qry = move(nqry);
    }
    q = qry.size();

    int l = 0, r = q;
    while(l < r) {
        int mid = l + r >> 1;
        auto [L, R] = qry[mid];
        if(query(L, n) < query(1, R)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    int ans = 0;
    if(l < q) {
        auto [L, R] = qry[l];
        ans = max(ans, query(L, R));
    }
    if(l > 0) {
        auto [L, R] = qry[l - 1];
        ans = max(ans, query(L, R));
    }

    cout << "! " << ans << endl;
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
