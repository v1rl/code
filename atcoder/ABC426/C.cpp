#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
*/

const int inf = 1e9;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> bk(n + 1, 1);
    bk[0] = 0;
    int base = 1;
    while(q --) {
        int x, y;
        cin >> x >> y;
        int num = 0;
        while(base <= x) {
            num += bk[base];
            bk[y] += bk[base];
            base ++;
        }
        cout << num << '\n';
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