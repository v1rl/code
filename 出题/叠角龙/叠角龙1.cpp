#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*
*/

const int inf = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<int> pre(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    deque<int> q;
    q.push_back(0);
    int ans = -inf;
    for(int i = 1; i <= n; i ++) {
        if(q.size() && q.front() < i - k) {
            q.pop_front();
        }

        ans = max(ans, pre[i] - pre[q.front()]);
        
        while(q.size() && pre[q.back()] >= pre[i]) {
            q.pop_back();
        }
        q.push_back(i);
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
