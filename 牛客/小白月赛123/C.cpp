#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
*/

const i64 inf = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = n; i >= 1; i --) {
        a[i] -= a[i - 1];
        a[i] = -a[i];
    }
    int l = 1, r = 1e9 + 2;

    bool f = true;
    for(int i = 1; i <= n; i ++) {
        if(a[i] >= 0) {
            f = false;
            break;
        }
    }
    if(f) {
        cout << 0 << '\n';
        return;
    }

    auto check = [&](int mid) {
        i64 x = 0;
        for(int i = 1; i <= n; i ++) {
            // 需要严格递增，在加1基础上再执行上取整
            x += max(0, (a[i] + mid) / mid);
        }
        return x <= m;
    };

    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    // 注意本题数据范围陷阱（我提醒出题人加的1e9 + 1样例，快夸我）
    cout << (l == 1e9 + 2 ? -1 : l) << '\n';
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