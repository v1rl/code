#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 2e9;

/*
*/

void solve() {
    array<int, 2> a[3];
    int sa = 0, sb = 0;
    for(int i = 0; i < 3; i ++) {
        cin >> a[i][0] >> a[i][1];
        sa += a[i][0], sb += a[i][1];
    }
    for(int i = 0; i < 3; i ++) {
        if(a[i][0] == sa / 3 && a[i][1] == sb / 3) {
            cout << i + 1 << '\n';
            break;
        }
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