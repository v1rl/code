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

    int t = x1 * y2 - x2 * y1;
    if(y1 == y2) {
        if(abs(t) == 4) {
            cout << 0 << '\n';
        } else {
            cout << "no answer" << '\n';
        }
        return;
    }
    cout << fixed << setprecision(15);
    cout << (t - 4.0) / (y2 - y1) << '\n';
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