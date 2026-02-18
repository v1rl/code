#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> kth;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(a[i] % 5 == 0) {
            int upx = a[i] / 5 * 7;
            int lox = a[i] / 5 * 3;
            kth.emplace_back(upx);
            kth.emplace_back(lox);
        }
        kth.emplace_back(a[i]);
    }

    sort(kth.begin(), kth.end());
    kth.erase(unique(kth.begin(), kth.end()), kth.end());

    int S = kth.size();
    auto rank = [&](int x) {
        return lower_bound(kth.begin(), kth.end(), x) - kth.begin();
    };

    vector<int> pre(S), suf(S);
    vector<int> rk(n);
    for(int i = 0; i < n; i ++) {
        rk[i] = rank(a[i]);
        suf[rk[i]] ++;
    }

    i64 ans = 0;
    for(int i = 0; i < n; i ++) {
        suf[rk[i]] --;
        if(a[i] % 5 != 0) {
            pre[rk[i]] ++;
            continue;
        }
        int upx = rank(a[i] / 5 * 7), lox = rank(a[i] / 5 * 3);
        ans += 1ll * pre[upx] * pre[lox];
        ans += 1ll * suf[upx] * suf[lox];
        pre[rk[i]] ++;
    }

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
