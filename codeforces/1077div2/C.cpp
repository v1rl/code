#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*
*/

const int inf = 1e9 + 10;

void solve() {
    int n;
    cin >> n;

    int mx = 0, mn = inf;
    vector<int> org(n + 1);
    vector<array<int, 2>> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i][0];
        org[i] = a[i][0];
        a[i][1] = i;
        mx = max(mx, a[i][0]);
        mn = min(mn, a[i][0]);
    }

    stable_sort(a.begin() + 1, a.end());

    auto check = [&](int mid) {
        for(int i = 1; i <= n; i ++) {
            int f = a[i][1];
            if(f == i) {
                continue;
            }
            if(abs(org[f] - a[i][0]) >= mid || (mx - org[f] >= mid && mx - a[i][0] >= mid) || (org[f] - mn) >= mid && (a[i][0] - mn) >= mid) {
                ;
            } else {
                return false;
            }
        }
        return true;
    };

    int l = 1, r = mx - mn + 1;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << (l == mx - mn + 1 ? -1 : l) << '\n';
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