#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for(int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y, i};
    }

    sort(a.begin(), a.end(), greater());

    int mx = 0;
    int ans = 0;
    deque<int> vec;
    for(int i = 0; i < n; i ++) {
        vector<int> cur;
        int cnt = 1;
        int x = a[i][0], mn = a[i][1];
        cur.emplace_back(a[i][2]);

        int j = 0;
        int res = cnt + min(mx, mn);
        if(res > ans) {
            ans = res;
            while(j < cur.size()) {
                vec.emplace_back(cur[j]);
                j ++;
            }
        }

        while(i + 1 < n && a[i + 1][0] == x) {
            i ++;
            cnt ++;
            mn = a[i][1];
            cur.emplace_back(a[i][2]);

            int res = cnt + min(mx, mn);
            if(res > ans) {
                ans = res;
                while(j < cur.size()) {
                    vec.emplace_back(cur[j]);
                    j ++;
                }
            }
        }

        while(vec.size() > ans) {
            vec.pop_front();
        }

        mx = ans;
    }

    cout << ans << '\n';
    for(auto c : vec) {
        cout << c + 1 << ' ';
    }
    cout << '\n';
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
