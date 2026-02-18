#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

#define double long double
typedef tuple<double, i64, i64> tp;

/*
*/

const int mod = 998244353;
const int inf = 1e9 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<i64, 2>> a(n);
    priority_queue<tp> heap;

    double ans = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }

    for(auto [x, y] : a) {
        ans += sqrtl(1ll * x * x + y * y);
        heap.push({sqrtl(1ll * x * x + y * y) - sqrt(1ll * x * x + (y - 1) * (y - 1)), x, y});
    }

    while(m -- && heap.size()) {
        auto [d, x, y] = heap.top();
        heap.pop();

        ans -= d;
        y --;

        if(y) {
            heap.push({sqrtl(1ll * x * x + y * y) - sqrt(1ll * x * x + (y - 1) * (y - 1)), x, y});
        }
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