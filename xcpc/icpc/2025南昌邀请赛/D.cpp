#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int n, _1, _2, _3;
    cin >> n >> _1 >> _2 >> _3;

    vector<vector<array<int, 2>>> range(3);
    while(n --) {
        array<int, 3> a, b;
        cin >> a[0] >> a[1] >> a[2];
        cin >> b[0] >> b[1] >> b[2];
        range[0].push_back({min(a[0], b[0]), max(a[0], b[0])});
        range[1].push_back({min(a[1], b[1]), max(a[1], b[1])});
        range[2].push_back({min(a[2], b[2]), max(a[2], b[2])});
    }

    auto get = [&](vector<array<int, 2>> &a) {
        sort(a.begin(), a.end());
        priority_queue<int, vector<int>, greater<int>> heap;
        int ans = 0;
        for(auto [x, y] : a) {
            while(!heap.empty() && heap.top() < x) {
                heap.pop();
            }
            ans = max(ans, (int)heap.size() + 1);
            heap.push(y);
        }
        return ans;
    };

    int ans = 0;
    for(int i = 0; i < 3; i ++) {
        ans = max(ans, get(range[i]));
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
