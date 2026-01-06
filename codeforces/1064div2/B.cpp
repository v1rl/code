#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/


const i64 inf = 1e18;

void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    int t = a / b;
    if(t >= n || a == b) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
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
