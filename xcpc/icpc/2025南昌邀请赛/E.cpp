#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    string s;
    cin >> s;

    s = '#' + s;

    mt19937_64 rng(5541123);

    vector<u64> v(26);
    for(int i = 0; i < 26; i ++) {
        v[i] = rng();
    }

    vector<array<int, 3>> query(q);
    for(int i = 0; i < q; i ++) {
        int x, y;
        cin >> x >> y;
        query[i] = {x, y, i};
    }

    int B = sqrt(n);
    vector<int> bel(n + 1);
    for(int i = 1; i <= n; i ++) {
        bel[i] = (i - 1) / B;
    }

    sort(query.begin(), query.end(), 
        [&](auto &a, auto &b) {
            if(bel[a[0]] != bel[b[0]]) {
                return bel[a[0]] < bel[b[0]];
            }
            if(bel[a[0]] & 1) {
                return a[1] > b[1];
            }
            return a[1] < b[1];
        });

    vector<u64> pre(n + 1);
    vector<int> cnt(26);
    for(int i = 1; i <= n; i ++) {
        pre[i] = pre[i - 1];
        int ch = s[i] - 'a';
        cnt[ch] ++;
        if(cnt[ch] == k) {
            cnt[ch] -= k;
        }
        if(cnt[ch]) {
            pre[i] += v[ch];
        } else {
            pre[i] -= v[ch] * (k - 1);
        }
    }

    vector<u64> kth = pre;
    sort(kth.begin(), kth.end());
    kth.erase(unique(kth.begin(), kth.end()), kth.end());
    auto rank = [&](u64 x) {
        return lower_bound(kth.begin(), kth.end(), x) - kth.begin();
    };

    vector<int> rk(n + 1);
    for(int i = 0; i <= n; i ++) {
        rk[i] = rank(pre[i]);
    }

    vector<int> num(kth.size());

    i64 res = 0;

    auto add = [&](int x) {
        res += num[rk[x]];
        num[rk[x]] ++;
    };
    auto del = [&](int x) {
        num[rk[x]] --;
        res -= num[rk[x]];
    };

    int l = 1, r = 0;
    vector<i64> ans(q);
    for(auto [x, y, id] : query) {
        x --;
        while(l > x) {
            add(-- l);
        }
        while(r < y) {
            add(++ r);
        }
        while(l < x) {
            del(l ++);
        }
        while(r > y) {
            del(r --);
        }
        ans[id] = res;
    }

    for(auto c : ans) {
        cout << c << '\n';
    }
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
