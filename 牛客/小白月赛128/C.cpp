#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
typedef pair<int, int> PII;
const int inf = 1e9;

/*

*/

void solve() {
    int n, a0, a1;
    cin >> n >> a0 >> a1;
    a1 = -a1;
    int s = 0;
    for(int i = 0; i < n; i ++) {
        int ta = abs(s + a0), tb = abs(s + a1);
        if(ta < tb) {
            s += a0;
            cout << 1;
        } else if(ta > tb) {
            s += a1;
            cout << 0;
        } else {
            int tz = min(ta + a0, abs(ta + a1));
            int tf = min(abs(-ta + a1), abs(-ta + a0));
            if(tz < tf) {
                if(s + a0 > 0) {
                    s += a0;
                    cout << 1;
                } else {
                    s += a1;
                    cout << 0;
                }
            } else {
                if(s + a0 < 0) {
                    s += a0;
                    cout << 1;
                } else {
                    s += a1;
                    cout << 0;
                }
            }
        }
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