#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e6 + 10;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> num(N);
    vector<int> a(n + 1);

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    vector<array<int, 3>> query(m);
    for(int i = 0; i < m; i ++) {
        int l, r;
        cin >> l >> r;
        query[i] = {l, r, i};
    }

    int len = sqrt(1ll * n * n / m) + 1;

    auto get = [&](int x) {
        return (x - 1) / len;
    };

    sort(query.begin(), query.end(), 
        [&](array<int, 3> a, array<int, 3> b)
        {
            int x = get(a[0]), y = get(b[0]);
            if(x != y) return x < y;
            else return a[1] < b[1];
        });

    int l = 1, r = 1;
    int res = 0;

    auto add = [&](int x) {
        if(++ num[a[x]] == 1) res ++;
    };

    auto del = [&](int x) {
        if(-- num[a[x]] == 0) res --;
    };

    vector<int> ans(m);

    for(auto [ql, qr, id] : query) {
        while(r <= qr) add(r ++);
        while(r > qr + 1) del(-- r);

        while(l < ql) del(l ++);
        while(l > ql) add(-- l);
        ans[id] = res;
    }

    for(auto x : ans) {
        cout << x << '\n';
    }
    return 0;
}