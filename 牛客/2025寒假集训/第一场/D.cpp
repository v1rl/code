#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), pre(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        pre[i] = max(pre[i - 1], min(n, a[i] + i));
    }

    auto check = [&](int mid) {
        int cur = 1;

        while(cur <= n && !a[cur]) {
            cur ++;
        }

        for(int i = 0; i < k && cur <= n; i ++) {
            for(int j = 0; j < mid && cur <= n && pre[cur] > cur; j ++) {
                cur = pre[cur];
            }
            cur ++;
            while(cur <= n && !a[cur]) {
                cur ++;
            }
        }

        return cur == n + 1;
    };

    int l = 0, r = n;
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << (l == n ? -1 : l) << '\n';
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