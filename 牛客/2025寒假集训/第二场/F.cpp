#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

const int mod = 998244353;
const int inf = 1e9 + 7;

void solve() {
    i64 a;
    cin >> a;
    int nd = 32 - __builtin_clz(a);
    i64 b = a;
    while(__builtin_ctz(b) < nd) {
        b <<= 1;
    }
    cout << b << ' ' << a + b << '\n';
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