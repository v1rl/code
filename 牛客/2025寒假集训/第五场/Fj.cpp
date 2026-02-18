#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<i64, i64> PII;

/*
*/

const int mod = 1e9 + 7;

void solve() {
    i64 n, a, b;
    cin >> n >> a >> b;
    
    i64 ans = 0;
    for(int i = 0; i < 2; i ++) {
        for(int j = 0; j < 2; j ++) {
            i64 v = n - i * 7 - j * 8;
            i64 res = i * a + j * (a + b);
            if(v >= 0) {
                ans = max(ans, v / 2 * b + res);
            }
        }
    }

    for(int i = 0; i < 7; i ++) {
        for(int j = 0; j < 7; j ++) {
            i64 v = n - i * 2 - j * 8;
            i64 res = i * b + j * (a + b);
            if(v >= 0) {
                ans = max(ans, v / 7 * a + res);
            }
        }
    }

    for(int i = 0; i < 8; i ++) {
        for(int j = 0; j < 8; j ++) {
            i64 v = n - i * 2 - j * 7;
            i64 res = i * b + j * a;
            if(v >= 0) {
                ans = max(ans, v / 8 * (a + b) + res);
            }
        }
    }

    cout << ans << '\n';
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
