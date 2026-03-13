#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<double, int> PII;

/*
*/

const int mod = 998244353;
const int inf = 1e9 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i ++) {
        cin >> x[i] >> y[i];
    }

    priority_queue<PII> heap;
    for(int i = 0; i < n; i ++) {
        heap.push({hypot(x[i], y[i]) - hypot(x[i], y[i] - 1), i});
    }

    while(m && heap.size()) {
        auto [_, i] = heap.top();
        heap.pop();

        y[i] --;
        if(y[i] > 0) {
            heap.push({hypot(x[i], y[i]) - hypot(x[i], y[i] - 1), i});
        }

        m --;
    }

    double ans = 0;
    for(int i = 0; i < n; i ++) {
        ans += hypot(x[i], y[i]);
    }

    cout << fixed << setprecision(15);
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