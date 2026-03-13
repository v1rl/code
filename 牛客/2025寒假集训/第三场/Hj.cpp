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

    if(y1 == y2) {
        if(abs(y1 * (x1 - x2)) == 4) {
            cout << 0 << '\n';
        } else {
            cout << "no answer" << '\n';
        }
        return;
    }

    double x = x1 + (double)(0 - y1) / (y2 - y1) * (x2 - x1);
    x += 4.0 / (y1 - y2);
    cout << x << '\n';
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