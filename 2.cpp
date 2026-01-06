#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    double ans = 1.0;
    double bs = 0.98;
    for(int i = 0; i < 50; i ++) {
        ans *= bs;
    }

    bs -= 0.02;
    for(int i = 50; i < 78; i ++) {
        ans *= bs;
        bs -= 0.02;
    }

    ans *= (1 - bs);
    printf("%.10lf", ans);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
}
