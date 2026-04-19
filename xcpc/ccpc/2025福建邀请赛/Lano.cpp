#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> a, b;
    for(int i = 1; i <= n * 2; i ++) {
        int x;
        cin >> x;
        if(i & 1) {
            a.emplace_back(x);
        } else {
            b.emplace_back(x);
        }
    }

    i64 sa = accumulate(a.begin(), a.end(), 0ll);
    i64 sb = accumulate(b.begin(), b.end(), 0ll);
    if(sa > sb) {
        swap(sa, sb);
        swap(a, b);
    }
    i64 d = sb - sa;

    i64 ans = min(sa, sb);
    sort(b.begin(), b.end());
    for(auto x : a) {
        int l = 0, r = n;
        while(l < r) {
            int mid = l + r >> 1;
            if((b[mid] - x) * 2 >= d) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if(l != n) {
            int t = b[l] - x;
            ans = max(ans, min(sa + t, sb - t));
        }

        l = -1, r = n - 1;
        while(l < r) {
            int mid = l + r + 1 >> 1;
            if((b[mid] - x) * 2 <= d) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if(l != -1) {
            int t = b[l] - x;
            ans = max(ans, min(sa + t, sb - t));
        }
    }

    cout << ans << '\n';
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
