#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(100001);
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        a[x] ++;
    }
    queue<i64> q1, q2;
    for(int i = 1; i <= 100000; i ++) {
        while(a[i]) {
            q1.push(i);
            a[i] --;
        }
    }

    i64 ans = 0;
    while(q1.size() + q2.size() > 1) {
        i64 x, y;
        if(q2.empty() || (!q1.empty() && q1.front() < q2.front())) {
            x = q1.front();
            q1.pop();
        } else {
            x = q2.front();
            q2.pop();
        }
        if(q2.empty() || (!q1.empty() && q1.front() < q2.front())) {
            y = q1.front();
            q1.pop();
        } else {
            y = q2.front();
            q2.pop();
        }
        ans += x + y;
        q2.push(x + y);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}