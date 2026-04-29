#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int n, m, p1, p2;
    cin >> n >> m >> p1 >> p2;
    int cnt1 = 0, cnt2 = 0;

    int pos1 = 0, pos2 = 0;
    int ans1 = 0, ans2 = 0;

    for(int i = 0; i < n; i ++) {
        int x, v, k;
        cin >> x >> v >> k;
        if(cnt1 <= 0) {
            if(abs(pos1 - x) * k <= p1) {
                p1 -= abs(pos1 - x) * k;
                cnt1 = m;
                ans1 += v;
                cnt2 --;
                pos1 = x;
                continue;
            }
        }
        if(cnt2 <= 0) {
            if(abs(pos2 - x) * k <= p2) {
                p2 -= abs(pos2 - x) * k;
                cnt2 = m;
                ans2 += v;
                cnt1 --;
                pos2 = x;
                continue;
            }
        }

        cnt1 --, cnt2 --;
    }

    cout << "Smelly: " << ans1;
    cout << ", ";
    cout << "Fragrant: " << ans2 << '\n';
    if(ans1 > ans2) {
        cout << "Smelly" << '\n';
    } else if(ans1 < ans2) {
        cout << "Fragrant" << '\n';
    } else {
        cout << "Peace" << '\n';
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
