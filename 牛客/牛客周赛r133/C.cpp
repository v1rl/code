#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
typedef pair<int, int> PII;

/*
*/

const i64 inf = 1e18 + 10;
const int mod = 998244353;

void solve() {
    i64 x, l, r;
    cin >> x >> l >> r;

    i64 v = 1;
    for(int i = 2; i <= x / i; i ++) {
        if(x % i == 0) {
            int cnt = 0;
            while(x % i == 0) {
                x /= i;
                cnt ++;
            }
            if(cnt & 1) {
                v *= i;
            }
        }
    }
    if(x > 1) {
        v *= x;
    }

    l = (l + v - 1) / v;
    r /= v;

    i64 t = l;
    l = sqrt(l);
    if(l * l < t) {
        l ++;
    }
    r = sqrt(r);

    if(l <= r) {
        cout << v * l * l << '\n';
    } else {
        cout << -1 << '\n';
    }
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
