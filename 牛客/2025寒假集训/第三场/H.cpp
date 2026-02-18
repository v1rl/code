#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*

*/

const int mod = 998244353;
const int inf = 1e9 + 7;

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int dx = x1 - x2, dy = y1 - y2;

    if(dy == 0) {
        if(dx * y1 == 4 || dx * y1 == -4) {
            cout << 0;
        } else {
            cout << "no answer";
        }
    } else {
        double ans = (double)(4 - dx * y1) / dy + x1;
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(15);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}